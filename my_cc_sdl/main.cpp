#include "game.hpp"
#include "build.hpp"
#include "shop.hpp"
#include "passiveGen.hpp"
#include "RecSave.hpp"

#include <time.h>
#include <thread>
#include <mutex>

Game *game = nullptr;
Build *build = nullptr;
Shop *shop = nullptr;
PassiveGen *passiveGen = nullptr;
RecSave *recSave = nullptr;

void passiveGeneration()
{
    while(true)
    {
        passiveGen->generation();
        Sleep(1000);
    }
}

void playGame()
{
    const int FPS = 15;
    const int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    game = new Game();

    game->init("Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while (game->running())
    {
        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime)
        {
            SDL_Delay(frameDelay - frameTime);
        }

    }

    game->clean();

}

void cleanCmd()
{
    //Cleaning the CMD screen with 50 lines of blank
    for(int i; i<50; i++)
    {
        std::cout<<std::endl;
    }

}

void buildMenu() //use test.hpp and test.cpp
{
    build = new Build();

    int buildRun = true;
    while(buildRun)
    {
        buildRun = build->build();
    }
}

void shopMenu() //use shop.hpp and shop.cpp
{
    //Enter the shop menu
    int shopRun = true;
    while(shopRun)
    {
        shopRun = shop->shop();
        if(shopRun==2){buildMenu();}
    }
}

void timeSeparation()
{
    //Take date and time of the moment
    time_t rawtime;
    time(&rawtime);
    std::string fullTime = asctime(localtime(&rawtime));
    //std::cout << fullTime;

    //Separation of day and time

    std::string secondes (""); std::string minutes (""); std::string hours ("");
    for(int i=17;i<19;i++){secondes += fullTime[i];}
    for(int i=14;i<16;i++){minutes += fullTime[i];}
    for(int i=11;i<13;i++){hours += fullTime[i];}
    //std::cout << hours <<std::endl; std::cout << minutes << std::endl; std::cout << secondes << std::endl;
    int hrs = std::stoi(hours), mts = std::stoi(minutes), sec = std::stoi(secondes);
    int L[3] = {hrs, mts, sec};
}

void gaming()
{
    int gameRun = 1;

    while(gameRun == 1)
    {
        std::string choice = "first";

        timeSeparation();
        std::string nCookiies;
        std::ifstream Xfile("gameSave/saveCookiies.txt");
        getline(Xfile,nCookiies);
        int cookiies = std::stoi(nCookiies);
        Xfile.close();

        std::cout << "######################################" << std::endl;
        std::cout << "## Select 'start' to start the Game ##              Cookiies = =" << std::endl;
        std::cout << "## Select 'shop' to enter the shop  ##                "<<cookiies<< std::endl;
        std::cout << "## Select 'build' to enter building ##" << std::endl;
        std::cout << "######################################" << std::endl;

        std::cout << "## Your choice : ##" << std::endl;
        std::cout << "## "; std::cin >> choice;

        if(choice == "start" || choice =="1")
        {
            playGame();
            cleanCmd();
        }

        else if(choice == "shop" || choice=="s")
        {
            shopMenu();
        }

        else if(choice=="build" || choice=="b")
        {
            buildMenu();
        }

        else if(choice == "quit")
        {
            cleanCmd();

            std::string quit;
            std::cout << "Sure you want to quit ? yes / no : "; std::cin >> quit;
            if(quit == "yes"){break;}
            else{cleanCmd();}
        }

        else {cleanCmd();}
    }

}


int main(int argc, char** argv)
{
    std::cout << "To play :"<<std::endl;
    std::cout << "write what you want to do in the CMD console," << std::endl;
    std::cout << "then press Enter to confirm your choice." <<  std::endl;
    std::cout << std::endl;
    Sleep(10000);
    cleanCmd();

    recSave->recup();

    cleanCmd();

    std::thread t1 (gaming);
    std::thread t2 (passiveGeneration);
    t1.join();
    t2.join();
}
