#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <regex>
#include "cfg.h"
#include "langs.cc"

const std::string cfg_input::version = "3.0.2";
std::vector<std::string> commands {
    "blockUser",
    "removeBlockFromUser",
    "banGuildMember",
    "clear",
    "version",
    "queries",
    "querydelete",
    "purgelogs",
    "logs",
    "captchas",
    "makerole",
    "unverify"
};

std::vector<std::string> cfg_dcmd_dec::cmdnames = commands;

std::string* cfg_util::dstream::getGameName() const
{
    return this->gameName;
}

void cfg_util::dstream::setGameName(std::string& name)
{
    this->gameName = &name;
}

std::string* cfg_util::dstream::getStreamURL() const
{
    return this->streamURL;
}

void cfg_util::dstream::setStreamURL(std::string& url)
{
    this->streamURL = &url;
}

std::string* cfg_util::dcommand::getCommandName() const
{
    return this->commandName;
}

void cfg_util::dcommand::setCommandName(std::string& name)
{
    this->commandName = &name;
}

std::string* cfg_util::dcommand::getExecutionName() const
{
    return this->execName;
}

void cfg_util::dcommand::setExecutionName(std::string& name)
{
    this->execName = &name;
}

std::vector<std::string>* cfg_util::dcommand::getContributors() const
{
    return this->contributors;
}

void cfg_util::dcommand::setContributors(std::vector<std::string>& contributors)
{
    this->contributors = &contributors;
}

std::string cfg_util::dcommand::addContributor(std::string new_contrib)
{
    (this->contributors)->push_back(new_contrib);
    return new_contrib;
}

bool cfg_util::dcommand::isEnabled() const
{
    return this->enabled;
}

void cfg_util::dcommand::setStatus(bool& status)
{
    this->enabled = &status;
}

int main()
{
    cfg_util::dstream* stream = new cfg_util::dstream;
    std::ofstream file("config.json");

	// Language(s) part
	std::ifstream options("cfg_options.txt");
	char langcode = 0;
	if (options) {
		std::string temp, content;
		while(getline(options, temp)) {
			content += temp + "\n";
		}
		std::smatch match;
		std::string result;
		std::regex lang_find_regex("LANG=(\\w+)");
		if(std::regex_search(temp, match, lang_find_regex) && match.size() > 1) {
			result = match.str(1);
			if (result == "en") langcode = 0;
			else if (result == "de") langcode = 1;
			else langcode = 0;
		}
	}
	options.close();
	
	
    if(!file)
    {
    	std::cout << translations::getTranslation(&langcode, "OFSTR_ERROR");
    	char a;
    	std::cin.ignore();
    	std::cin.get(a);
	}
    std::cout << std::endl << "==== DiscordCaptcha Config File Setup v1.3 ====" << std::endl
    << "-------------------------------" << std::endl
    << "1.) " << translations::getTranslation(&langcode, "MENU_RUN_CFG") << std::endl
    << "2.) " << translations::getTranslation(&langcode, "MENU_CREDITS") << std::endl
    << "3.) " << translations::getTranslation(&langcode, "MENU_EXIT") << std::endl
	<< "4.) " << translations::getTranslation(&langcode, "MENU_CHANGE_LANG") << std::endl
    << "-------------------------------" << std::endl
    << "> ";
    int input;
    std::cin >> input;
    std::cout << std::endl;

    switch(input)
    {
    case 1:
	{
	    do {
            std::cout << translations::getTranslation(&langcode, "C_BOT_TOKEN");
            std::cin.ignore();
            getline(std::cin, cfg_input::token);
        } while(cfg_input::token.size() < 30);
        do {
            std::cout << translations::getTranslation(&langcode, "C_CLIENT_ID");
            std::cin >> cfg_input::clientid;
        } while(!std::regex_match(cfg_input::clientid, std::regex("^\\d{15,20}$")));

        std::cout << translations::getTranslation(&langcode, "C_PREFIX");
        std::cin >> cfg_input::prefix;

        std::cout << translations::getTranslation(&langcode, "C_LOGCHAT");
        std::cin >> cfg_input::logChannel;

        std::cout << translations::getTranslation(&langcode, "C_VERIFIEDROLE");
        std::cin >> cfg_input::verifiedRole;

        std::string strname, strurl;
        std::cout << translations::getTranslation(&langcode, "C_STREAMNAME");
        std::cin.ignore();
        getline(std::cin, strname);

        std::cout << translations::getTranslation(&langcode, "C_STREAMURL");
        std::cin >> strurl;

        stream->setGameName(strname);
        stream->setStreamURL(strurl);

        std::string* evalALWDs = new std::string;
        std::cout << translations::getTranslation(&langcode, "C_EVALALWD");
        std::cin >> *evalALWDs;
        cfg_input::eval = *evalALWDs == "y";
        delete evalALWDs;

        do {
            std::cout << translations::getTranslation(&langcode, "C_OWNER");
            std::cin >> cfg_input::owner;
        } while(!std::regex_match(cfg_input::owner, std::regex("^\\d{15,20}$")));

        do {
            std::cout << translations::getTranslation(&langcode, "C_OWNERTAG");
            std::cin.ignore();
            getline(std::cin, cfg_input::ownerTag);
        } while(!std::regex_match(cfg_input::ownerTag, std::regex("^.{1,20}#\\d{4}$")));

        std::string* logging = new std::string;
        std::cout << translations::getTranslation(&langcode, "C_LOGTODB");
        std::cin >> *logging;
        cfg_input::logToDB = *logging == "y";
        delete logging;

        std::string* ctype = new std::string;
        std::cout << translations::getTranslation(&langcode, "C_CAPTCHATYPE");
        std::cin >> *ctype;
        cfg_input::ctype = (*ctype == "IMAGES") ? cfg_util::captchaType::IMAGE : cfg_util::captchaType::TEXT;
        delete ctype;

        file << "{" << std::endl
             << "\t\"token\": \"" << cfg_input::token << "\"," << std::endl
             << "\t\"clientid\": \"" << cfg_input::clientid << "\"," << std::endl
             << "\t\"prefix\": \"" << cfg_input::prefix << "\"," << std::endl
             << "\t\"version\": \"" << cfg_input::version << "\"," << std::endl
             << "\t\"chat\": \"" << cfg_input::logChannel << "\"," << std::endl
             << "\t\"userrole\": \"" << cfg_input::verifiedRole << "\"," << std::endl
             << "\t\"streamingGame\": \"" << *stream->getGameName() << "\"," << std::endl
             << "\t\"streamingLink\": \"" << *stream->getStreamURL() << "\"," << std::endl
             << "\t\"evalAllowed\": \"" << (cfg_input::eval == true ? "true" : "false") << "\"," << std::endl
             << "\t\"captchaType\": \"" << (cfg_input::ctype == cfg_util::captchaType::IMAGE ? "image" : "text") << "\"," << std::endl
             << "\t\"commands\": {" << std::endl;

        std::cout << "------------------------------" << std::endl
                  << "Commands" << std::endl
                  << "------------------------------" << std::endl;
        int index = 0;
        for(std::string& cmd : cfg_dcmd_dec::cmdnames)
        {
            std::string* input = new std::string;
            std::cout << "Command '" << cmd << "' | " << translations::getTranslation(&langcode, "C_CMDALIAS");
            std::cin >> *input;
            cfg_dcmd_dec::execnames.push_back(*input == "NULL" ? cmd : *input);
            std::cout << "Command '" << cmd << "' | " << translations::getTranslation(&langcode, "C_CMDALLOWSELF");
            std::cin.ignore();
            getline(std::cin, *input);
            if (*input == "y") cfg_dcmd_dec::allowSelf.push_back(true);
            else cfg_dcmd_dec::allowSelf.push_back(false);
            std::cout << "Command '" << cmd << "' | " << translations::getTranslation(&langcode, "C_CMDENABLE");
            std::cin >> *input;
            cfg_dcmd_dec::cmdstatuses.push_back(*input == "y");
            std::cout << std::endl;

            file << "\t\t\"" << commands.at(index) << "\": {" << std::endl
                 << "\t\t\t\"command\": \"" << cfg_dcmd_dec::execnames.at(index) << "\"," << std::endl
                 << "\t\t\t\"contributors\": [ \"" << (cfg_dcmd_dec::allowSelf.at(index) ? cfg_input::ownerTag : "") << "\" ]," << std::endl
                 << "\t\t\t\"enabled\": " << (cfg_dcmd_dec::cmdstatuses.at(index) ? "true" : "false") << std::endl
                 << "\t\t}" << (cmd != "unverify" ? "," : "") << "\n";

            delete input;
            index++;
        }
        file << "\t}" << std::endl
             << "}";
        file.close();
        
        std::cout << translations::getTranslation(&langcode, "CFG_FINISHED") << std::endl
				  << translations::getTranslation(&langcode, "EXITPRG");
        
        char a;
        std::cin.ignore();
        std::cin.get(a);
        break;
	}
    case 2:
        std::cout << std::endl
                  << translations::getTranslation(&langcode, "COMPILEINFO") << std::endl
                  << translations::getTranslation(&langcode, "DCAPTCHA_BUGS") << std::endl
                  << translations::getTranslation(&langcode, "DCAPTCHA_LIBS") << std::endl
                  << translations::getTranslation(&langcode, "BACKTOMENU");
        char a;
        std::cin.ignore();
        std::cin.get(a);
#ifdef _WIN32
        std::system("cls");
#elif __linux__
        std::system("clear");
#endif
        main();
        break;
    case 3:
        file.close();
        delete stream;
        std::exit(0);
        break;
	case 4:
		{
		std::ifstream *testfile = new std::ifstream {"cfg_options.txt"};
		std::string _lang;
		do {
			std::cout << "Choose a language (de/en): ";
			std::cin >> _lang;
		} while(_lang == "");
			
		if (!(*testfile)) {
			std::ofstream *optionfile = new std::ofstream {"cfg_options.txt"};
			*optionfile << "LANG=" << _lang;
			optionfile->close();
			delete optionfile;
		} else {
			std::string filecontents, templine;
			
			while(getline(*testfile, templine)) {
				filecontents += templine;
			}
			
			std::ofstream *optionfile = new std::ofstream {"cfg_options.txt"};
			if (filecontents.find("LANG=") != std::string::npos) {
				std::regex rgx("LANG=\\w+");
				std::string a = std::regex_replace(filecontents, rgx, "LANG=" + _lang);
				*optionfile << a;
			} else {
				*optionfile << "LANG=" << _lang;
			}
			optionfile->close();
			delete optionfile;
		}
		
		testfile->close();
		delete testfile;
		break;
		}
    default:
#ifdef _WIN32
        std::system("cls");
#elif __linux__
        std::system("clear");
#endif
        main();
        break;
    }

    delete stream;
    return 0;
}
