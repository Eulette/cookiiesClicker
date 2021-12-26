#include "test.hpp"


Test::Test()
{
    //ctor
}

Test::~Test()
{
    //dtor
}

void cleanCmd1()
{
    //Cleaning the CMD screen with 50 lines of blank
    for(int i; i<50; i++)
    {
        std::cout<<std::endl;
    }

}

int Test::build()
{
    //import cookiies number
    std::string nCookiies;
    std::ifstream fileC("saveCookiies.txt");
    getline(fileC,nCookiies);
    int cookiies = std::stoi(nCookiies);
    fileC.close();

    //Builds definition
    std::string nBuild;
    std::ifstream file("saveBuild.txt");

    getline(file,nBuild);
    std::string furnace = nBuild;
    getline(file,nBuild);
    int furnaceNumber = std::stoi(nBuild);
    getline(file,nBuild);
    int furnacePrice = std::stoi(nBuild);
    getline(file,nBuild);
    int furnaceUnlock = std::stoi(nBuild);


    getline(file,nBuild);
    std::string cauldron = nBuild;
    getline(file,nBuild);
    int cauldronNumber = std::stoi(nBuild);
    getline(file,nBuild);
    int cauldronPrice = std::stoi(nBuild);
    getline(file,nBuild);
    int cauldronUnlock = std::stoi(nBuild);


    getline(file,nBuild);
    std::string breadFurnace = nBuild;
    getline(file,nBuild);
    int breadFurnaceNumber = std::stoi(nBuild);
    getline(file,nBuild);
    int breadFurnacePrice = std::stoi(nBuild);
    getline(file,nBuild);
    int breadFurnaceUnlock = std::stoi(nBuild);


    getline(file,nBuild);
    std::string workshop = nBuild;
    getline(file,nBuild);
    int workshopNumber = std::stoi(nBuild);
    getline(file,nBuild);
    int workshopPrice = std::stoi(nBuild);
    getline(file,nBuild);
    int workshopUnlock = std::stoi(nBuild);


    getline(file,nBuild);
    std::string factory = nBuild;
    getline(file,nBuild);
    int factoryNumber = std::stoi(nBuild);
    getline(file,nBuild);
    int factoryPrice = std::stoi(nBuild);
    getline(file,nBuild);
    int factoryUnlock = std::stoi(nBuild);


    getline(file,nBuild);
    std::string city = nBuild;
    getline(file,nBuild);
    int cityNumber = std::stoi(nBuild);
    getline(file,nBuild);
    int cityPrice = std::stoi(nBuild);
    getline(file,nBuild);
    int cityUnlock = std::stoi(nBuild);


    getline(file,nBuild);
    std::string country = nBuild;
    getline(file,nBuild);
    int countryNumber = std::stoi(nBuild);
    getline(file,nBuild);
    int countryPrice = std::stoi(nBuild);
    getline(file,nBuild);
    int countryUnlock = std::stoi(nBuild);


    file.close();


    cleanCmd1();

    std::string choiceBuild;

    std::cout << "#################################################" << std::endl;
    std::cout << "## Current  Builds  :                           " << std::endl;
    std::cout << "##                                                " << std::endl;

    if(furnaceUnlock)
    {
    std::cout << "##   Furnace LVL "<<furnaceNumber<<"             " << std::endl;
    std::cout << "##                                 upgrade price : "<<furnacePrice<<"               " << std::endl;
    }
    if(cauldronUnlock)
    {
    std::cout << "##   Cauldron LVL "<<cauldronNumber<<"             " << std::endl;
    std::cout << "##                                 upgrade price : "<<cauldronPrice<<"               " << std::endl;
    }
    if(breadFurnaceUnlock)
    {
    std::cout << "##   Bread Furnace LVL "<<breadFurnaceNumber<<"             " << std::endl;
    std::cout << "##                                 upgrade price : "<<breadFurnacePrice<<"              " << std::endl;
    }
    if(workshopUnlock)
    {
    std::cout << "##   Workshop LVL "<<workshopNumber<<"             " << std::endl;
    std::cout << "##                                 upgrade price : "<<workshopPrice<<"             " << std::endl;
    }
    if(factoryUnlock)
    {
    std::cout << "##   Factory LVL "<<factoryNumber<<"             " << std::endl;
    std::cout << "##                                 upgrade price : "<<factoryPrice<<"              " << std::endl;
    }
    if(cityUnlock)
    {
    std::cout << "##   City LVL "<<cityNumber<<"             " << std::endl;
    std::cout << "##                                 upgrade price : "<<cityNumber<<"              " << std::endl;
    }
    if(countryUnlock)
    {
    std::cout << "##   Country LVL "<<countryNumber<<"             " << std::endl;
    std::cout << "##                                 upgrade price : "<<countryPrice<<"              " << std::endl;
    }

    if(cookiies >= furnacePrice & furnaceUnlock == 0)
    {
    std::cout << "##   'f' to Unlock your first furnace " << std::endl;
    std::cout << "##    furnace price : "<<furnacePrice<<" cookiies "<< std::endl;
    }

    if(cookiies >= cauldronPrice & cauldronUnlock == 0)
    {
    std::cout << "##   'c' to Unlock your first furnace " << std::endl;
    std::cout << "##    cauldron price : "<<cauldronPrice<<" cookiies "<< std::endl;
    }
    if(cookiies >= breadFurnacePrice & breadFurnaceUnlock == 0)
    {
    std::cout << "##   'b' to Unlock your first bread furnace " << std::endl;
    std::cout << "##    bread furnace price : "<<breadFurnacePrice<<" cookiies "<< std::endl;
    }
    if(cookiies >= workshopPrice & workshopUnlock == 0)
    {
    std::cout << "##   'w' to Unlock your first workshop " << std::endl;
    std::cout << "##    worshop price : "<<workshopPrice<<" cookiies "<< std::endl;
    }
    if(cookiies >= factoryPrice & factoryUnlock == 0)
    {
    std::cout << "##   'fa' to Unlock your first cookiies's factory" << std::endl;
    std::cout << "##    factory price : "<<factoryPrice<<" cookiies "<< std::endl;
    }
    if(cookiies >= cityPrice & cityUnlock == 0)
    {
    std::cout << "##   'ci' to Unlock your first chocolate city  " << std::endl;
    std::cout << "##    city price : "<<cityPrice<<" cookiies "<< std::endl;
    }
    if(cookiies >= countryPrice & countryUnlock == 0)
    {
    std::cout << "##   'co' to Unlock your first country of cookiisation " << std::endl;
    std::cout << "##    country price : "<<countryPrice<<" cookiies "<< std::endl;
    }

    std::cout << "##                                                " << std::endl;
    std::cout << "##   Cookiies Number : "<<cookiies<<"             " << std::endl;
    std::cout << "## "<<std::endl;
    std::cout << "## Your choice : ##" << std::endl;
    std::cout << "## "; std::cin >> choiceBuild;

    if(choiceBuild=="furnace" || choiceBuild=="f")
    {
        if(cookiies >= furnacePrice)
        {
            furnaceUnlock = 1;
            furnaceNumber++;
            cookiies -= furnacePrice;
            furnacePrice += pow(1.5,furnacePrice);
        }
        else{std::cout<<std::endl; std::cout<<"Not enough Cookiies"; Sleep(1000);}
    }
    else if(choiceBuild=="cauldron" || choiceBuild=="c")
    {
        if(cookiies >= cauldronPrice)
        {
            cauldronUnlock = 1;
            cauldronNumber++;
            cookiies -= cauldronPrice;
            cauldronPrice += pow(1.6,cauldronPrice);
        }
        else{std::cout<<std::endl; std::cout<<"Not enough Cookiies"; Sleep(1000);}
    }
    else if(choiceBuild=="breadfurnace" || choiceBuild=="b")
    {
        if(cookiies >= breadFurnacePrice)
        {
        breadFurnaceUnlock = 1;
        breadFurnaceNumber++;
        cookiies -= breadFurnacePrice;
        breadFurnacePrice += pow(1.7,breadFurnacePrice);
        }
        else{std::cout<<std::endl; std::cout<<"Not enough Cookiies"; Sleep(1000);}
    }
    else if(choiceBuild=="workshop" || choiceBuild=="w")
    {
        if(cookiies >= workshopPrice)
        {
        workshopUnlock = 1;
        workshopNumber++;
        cookiies -= workshopPrice;
        workshopPrice += pow(1.8,workshopPrice);
        }
        else{std::cout<<std::endl; std::cout<<"Not enough Cookiies"; Sleep(1000);}
    }
    else if(choiceBuild=="factory" || choiceBuild=="fa")
    {
        if(cookiies >= factoryPrice)
        {
        factoryUnlock = 1;
        factoryNumber++;
        cookiies -= factoryPrice;
        factoryPrice += pow(1.9,factoryPrice);
        }
        else{std::cout<<std::endl; std::cout<<"Not enough Cookiies"; Sleep(1000);}
    }
    else if(choiceBuild=="city" || choiceBuild=="ci")
    {
        if(cookiies >= cityPrice)
        {
        cityUnlock = 1;
        cityNumber++;
        cookiies -= cityPrice;
        cityPrice += pow(2.0,cityPrice);
        }
        else{std::cout<<std::endl; std::cout<<"Not enough Cookiies"; Sleep(1000);}
    }
    else if(choiceBuild=="country" || choiceBuild=="co")
    {
        if(cookiies >= countryPrice)
        {
        countryUnlock = 1;
        countryNumber++;
        cookiies -= countryPrice;
        countryPrice += pow(2.5,countryPrice);
        }
        else{std::cout<<std::endl; std::cout<<"Not enough Cookiies"; Sleep(1000);}
    }

    else if(choiceBuild=="back")
    {
        cleanCmd1();
        return 0;
    }



    std::ofstream fileWrite;
    fileWrite.open ("saveBuild.txt");

    fileWrite << furnace << std::endl;
    fileWrite << furnaceNumber << std::endl;
    fileWrite << furnacePrice << std::endl;
    fileWrite << furnaceUnlock << std::endl;

    fileWrite << cauldron << std::endl;
    fileWrite << cauldronNumber << std::endl;
    fileWrite << cauldronPrice << std::endl;
    fileWrite << cauldronUnlock << std::endl;

    fileWrite << breadFurnace << std::endl;
    fileWrite << breadFurnaceNumber << std::endl;
    fileWrite << breadFurnacePrice << std::endl;
    fileWrite << breadFurnaceUnlock << std::endl;

    fileWrite << workshop << std::endl;
    fileWrite << workshopNumber << std::endl;
    fileWrite << workshopPrice << std::endl;
    fileWrite << workshopUnlock << std::endl;

    fileWrite << factory << std::endl;
    fileWrite << factoryNumber << std::endl;
    fileWrite << factoryPrice << std::endl;
    fileWrite << factoryUnlock << std::endl;

    fileWrite << city << std::endl;
    fileWrite << cityNumber << std::endl;
    fileWrite << cityPrice << std::endl;
    fileWrite << cityUnlock << std::endl;

    fileWrite << country << std::endl;
    fileWrite << countryNumber << std::endl;
    fileWrite << countryPrice << std::endl;
    fileWrite << countryUnlock << std::endl;

    fileWrite.close();

    std::ofstream fileCc;
    fileCc.open ("saveCookiies.txt");
    fileCc << cookiies << std::endl;
    std::cout <<"register";
    fileCc.close();

}
