#include "game.hpp"

std::list<int> cookiiesImport()
{
    //variable declaration
    std::string nCookiies;
    std::string nUpclic;

    std::ifstream file("gameSave/saveCookiies.txt"); //open the save file
    getline(file,nCookiies);
    int cookiies = std::stoi(nCookiies);

    //close the save file
    file.close();

    //import save for the shop
    std::ifstream fileShop("gameSave/saveShop.txt"); //open the save file
    getline(fileShop,nUpclic);
    int upclic = std::stoi(nUpclic);
    getline(fileShop,nUpclic);
    int upclicPrice = std::stoi(nUpclic);


    //insert into list
    std::list<int> liste = {cookiies,upclic,upclicPrice};

    //return the list of saved values
    return liste;
}

Game::Game()
{

}
Game::~Game()
{

}

void Game::init(const char *title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        //std::cout << "Subsysteme initialised" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
        if(window)
        {
            //std::cout << "Window created" << std::endl;
        }

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(renderer)
        {
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

            SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255);
            SDL_RenderPresent(renderer);
            SDL_RenderClear(renderer);

            //std::cout << "Renderer created" << std::endl;
        }

        isRunning = true;

        //recover saved values
        std::list<int> liste = cookiiesImport();
        std::list<int>::iterator range_begin = liste.begin();

        cookiies = liste.front();

        //bloc of list recover
        liste.erase(range_begin);

        upclic = liste.front();

        range_begin = liste.begin();

        liste.erase(range_begin);

        upclicPrice = liste.front();

        range_begin = liste.begin();

    } else{
        isRunning = false;
    }
}

void Game::handleEvents()
{
    mousePressed = false;

    SDL_Event event;
    SDL_PollEvent(&event);
    switch(event.type){
    case SDL_QUIT:
        isRunning = false;
        break;
    case SDL_MOUSEBUTTONDOWN:
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            mouseDown = true;
            mousePressed = true;
        }
        if(event.button.button == SDL_BUTTON_RIGHT)
        {
            mouseRightDown = true;
            mouseRightPressed = true;
        }
        break;
    case SDL_MOUSEBUTTONUP:
        if(event.button.button == SDL_BUTTON_LEFT)
        {
            mouseDown = false;
        }
        if(event.button.button == SDL_BUTTON_RIGHT)
        {
            mouseRightDown = false;
        }

        break;


    default:
        break;
    }
}

void Game::update()
{
    //cnt++;
    //std::cout << cnt << std::endl;
    int x, y;

    if(mousePressed)
    {
        std::string nCookiies;
        std::ifstream file("gameSave/saveCookiies.txt");
        getline(file,nCookiies);
        int cookiies = std::stoi(nCookiies);
        file.close();

        //count number of clic
        cookiies += upclic;
        std::cout<<"Cookiies == "<<cookiies<<std::endl;

        std::ofstream Nfile;
        Nfile.open ("gameSave/saveCookiies.txt");
        Nfile << cookiies << std::endl;
        Nfile.close();

        //Drawing rand color for rectangle
        rNumber = rand()%255;
        gNumber = rand()%255;
        bNumber = rand()%255;

        SDL_GetMouseState(&x,&y);
        //std::cout<<x<<std::endl;
        //std::cout<<y<<std::endl;

        SDL_SetRenderDrawColor(renderer, 200, 200, 200, 255); //background view
        SDL_RenderPresent(renderer);
        SDL_RenderClear(renderer);

        SDL_Rect plus1; //square shape near mouse
        SDL_SetRenderDrawColor(renderer, 250, 250, 250, 255);

        SDL_RenderDrawLine(renderer, x-15,y,x+15,y );
        SDL_RenderDrawLine(renderer, x,y-15,x,y+15 );
        SDL_RenderDrawLine(renderer, x+27,y-3,x+48,y-25 );
        SDL_RenderDrawLine(renderer, x+48,y-25,x+48,y+25 );

        SDL_RenderPresent(renderer);
        //Sleep(10000);

    }

    if(mouseRightPressed)
    {
        isRunning = false;
    }
}


void Game::render()
{
    //SDL_RenderClear(renderer);

    //This is where we draw red background

    //This is where we draw
    SDL_Rect r;
    r.x = 100;
    r.y = 100;
    r.w = 100;
    r.h = 100;
    SDL_SetRenderDrawColor(renderer, rNumber, gNumber, bNumber, 255);
    SDL_RenderFillRect(renderer, &r);
    SDL_RenderPresent(renderer);

    SDL_Rect rr;
    rr.x = 600;
    rr.y = 100;
    rr.w = 100;
    rr.h = 100;
    SDL_SetRenderDrawColor(renderer, rNumber, gNumber, bNumber, 255);
    SDL_RenderFillRect(renderer, &rr);
    SDL_RenderPresent(renderer);

    SDL_Rect rrr;
    rrr.x = 300;
    rrr.y = 350;
    rrr.w = 200;
    rrr.h = 50;
    SDL_SetRenderDrawColor(renderer, rNumber, gNumber, bNumber, 255);
    SDL_RenderFillRect(renderer, &rrr);
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    std::ofstream fileShop;
    fileShop.open("gameSave/saveShop.txt");
    fileShop << upclic << std::endl;
    fileShop << upclicPrice << std::endl;
    fileShop.close();

    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    //std::cout <<"game cleaned"<<std::endl;
}
