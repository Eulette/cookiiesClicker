#include "RecSave.hpp"

RecSave::RecSave()
{
    //ctor
}

RecSave::~RecSave()
{
    //dtor
}

RecSave::recup()
{
    std::cout << "######################################" << std::endl;
    std::cout << "## Select your save :                 " << std::endl;
    std::cout << "##                                    " << std::endl;

    std::string sLine;
    std::string jline;
    std::ifstream Cfile("gameSave/saveName.txt");
    std::ifstream CCfile("gameSave/SaveName.txt");
    while(getline(Cfile,sLine))
    {
        getline(CCfile,jline);
        std::cout <<"## "<<jline<<std::endl;
        std::cout <<"## "<<std::endl;
    }
    Cfile.close();
    CCfile.close();

    std::string saveChoice;
    std::cout << "## Save Choice : ";
    std::cin >> saveChoice;

    saveChoice = "saves/" + saveChoice + ".txt";

    std::string nBuild;

    std::ifstream file(saveChoice);


    getline(file,nBuild);
    int cookiies = std::stoi(nBuild);


    getline(file,nBuild);
    int upclic = std::stoi(nBuild);
    getline(file,nBuild);
    int upclicPrice = std::stoi(nBuild);


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


    //re write of file with saved one
    std::ofstream fileWrite;
    fileWrite.open ("gameSave/saveBuild.txt");

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
