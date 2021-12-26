#include "shop.hpp"

Shop::Shop()
{
    //ctor
}

Shop::~Shop()
{
    //dtor
}

void cleanCmd2()
{
    //Cleaning the CMD screen with 50 lines of blank
    for(int i; i<50; i++)
    {
        std::cout<<std::endl;
    }

}

Shop::shop()
{
    //import cookiies number
    std::string nCookiies;
    std::ifstream fileC("gameSave/saveCookiies.txt");
    getline(fileC,nCookiies);
    int cookiies = std::stoi(nCookiies);
    fileC.close();

    std::string nUpclic;
    std::ifstream fileShop("gameSave/saveShop.txt");
    getline(fileShop,nUpclic);
    int upclic = std::stoi(nUpclic);
    getline(fileShop,nUpclic);
    int upclicPrice = std::stoi(nUpclic);
    fileShop.close();

    cleanCmd2();

    std::string choiceShop;

    std::cout << "#################################################" << std::endl;
    std::cout << "## Available upgrades :                        " << std::endl;
    std::cout << "##                                             " << std::endl;
    if(cookiies>=upclicPrice){
    std::cout << "##  Clic Upgrade = up                          " << std::endl;
    std::cout << "##                                             " << std::endl;}
    std::cout << "#################################################" << std::endl;
    std::cout << "##                                             " << std::endl;
    std::cout << "##  Upclic at "<<upclic<<"                     " << std::endl;
    std::cout << "##         Up Price : "<<upclicPrice<<"        " << std::endl;
    std::cout << "##                                             " << std::endl;
    std::cout << "##  Cookiies : "<<cookiies<<"                  " << std::endl;
    std::cout << "##                                             " << std::endl;
    std::cout << "#################################################" << std::endl;
    std::cout << "##                                             ##" << std::endl;
    std::cout << "##  Back Main Menu = back                      ##" << std::endl;
    std::cout << "##                                             ##" << std::endl;
    std::cout << "#################################################" << std::endl;

    std::cout << "## "<<std::endl;
    std::cout << "## Your choice : ##" << std::endl;
    std::cout << "## "; std::cin >> choiceShop;


    if(choiceShop=="up")
    {
        if(cookiies>=upclicPrice)
        {
            upclic++;
            cookiies -= upclicPrice;
            upclicPrice += pow(1.2,upclic);
        }
        else{std::cout<<std::endl; std::cout<<"Not enough Cookiies"; Sleep(1000);}
    }

    else if(choiceShop=="back")
    {
        cleanCmd2();
        return 0;
    }

    else if(choiceShop=="build" || choiceShop=="b")
    {
        cleanCmd2();
        return 2;
    }

    std::ofstream fileShopWrite;
    fileShopWrite.open ("gameSave/saveShop.txt");
    fileShopWrite << upclic << std::endl;
    fileShopWrite << upclicPrice << std::endl;
    fileShopWrite.close();

    std::ofstream fileCookiiesWrite;
    fileCookiiesWrite.open ("gameSave/saveCookiies.txt");
    fileCookiiesWrite << cookiies << std::endl;
    fileCookiiesWrite.close();

}
