#include "C_Setting.h"

C_Setting::C_Setting()
{
    spdlog::info("loading settings");
    Load();

    font = new sf::Font;
    font->loadFromFile(settingdata.guifontname);
}

C_Setting::~C_Setting()
{
    Save();
}

bool C_Setting::Load()
{
    std::ifstream infile;
    infile.open(settingfile);
    if (infile.is_open())
    {
        std::string line;
        std::string left, right;
        auto pos = 0;
        while (std::getline(infile, line))
        {
            left = line.substr(0, line.find_first_of('='));
            right = line.substr(line.find_first_of('=') + 1);
            //std::cout << "Links " << left << "rechts " << right << std::endl;
            if (left == std::string("screenx"))
                std::cout << "SCREENX\n";
        }
        infile.close();
    }
    else
        {
            spdlog::error("ERROR: can't open the settingfile from : " + std::filesystem::absolute(settingfile).string() + " using default values");
        }

    return false;
}

bool C_Setting::Save()
{
    std::ofstream out;
    out.open(settingfile);
    out << "screenx=" << settingdata.window_width << std::endl;
    out << "screeny=" << settingdata.window_height << std::endl;
    out << "fullscreen=" << settingdata.fullscreen << std::endl;
    out << "assetpath=" << settingdata.assetpath.c_str() << std::endl;
    out << "guifontname=" << settingdata.guifontname << std::endl;
    out.close();


    spdlog::info("saveing settings");

    return false;
}

void C_Setting::Set(const unsigned int& id, ...)
{
}

auto C_Setting::Get(const unsigned int& id)
{
}
