#include "passiveGen.hpp"

PassiveGen::PassiveGen()
{
    //ctor
}

PassiveGen::~PassiveGen()
{
    //dtor
}

PassiveGen::generation()
{
    //import cookiies number
    std::string nCookiies;
    std::ifstream fileC("gameSave/saveCookiies.txt");
    getline(fileC,nCookiies);
    int cookiies = std::stoi(nCookiies);
    fileC.close();

    //Builds definition
    std::string nBuild;
    std::ifstream file("gameSave/saveBuild.txt");

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

    //Income
    int furnaceIncome = furnaceNumber * 1;
    int cauldronIncome = cauldronNumber * 3;
    int breadFurnaceIncome = breadFurnaceNumber * 5;
    int workshopIncome = workshopNumber * 10;
    int factoryIncome = factoryNumber * 30;
    int cityIncome = cityNumber * 50;
    int countryIncome = countryNumber * 100;

    cookiies += furnaceIncome + cauldronIncome + breadFurnaceIncome + workshopIncome + factoryIncome + cityIncome + countryIncome;


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

    std::ofstream fileCc;
    fileCc.open ("gameSave/saveCookiies.txt");
    fileCc << cookiies << std::endl;
    //std::cout <<"register : "<<cookiies<<std::endl;
    fileCc.close();

}
