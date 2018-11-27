#include "langs.h"

std::map<std::string, std::string> translations::de = {
	{ "MENU_RUN_CFG", "Ausführen" },
    { "MENU_CREDITS", "Mitwirkende & Disclaimer" },
    { "MENU_CHANGE_LANG", "Sprache ändern" },
    { "MENU_EXIT", "Programm beenden" },
    { "C_BOT_TOKEN", "Bot Token (kann auf Discord's Entwicklerseite gefunden werden): " },
    { "C_CLIENT_ID", "Client ID: " },
    { "C_PREFIX", "Prefix (worauf der Bot reagiert, z.B. das Ausrufezeichen in !verify): " },
    { "C_LOGCHAT", "Der Channel wo Verifizierungen geloggt werden sollen: " },
    { "C_VERIFIEDROLE", "ID der Rolle für verifizierte User: " },
    { "C_STREAMNAME", "The streaming game name (playing status): " },
    { "C_STREAMURL", "The URL of the stream (needs to be a valid twitch.tv one): " },
    { "C_EVALALWD", "JavaScript eval erlauben (nicht empfohlen; hilfreich für Entwickler | Antworte mit y oder n): " },
    { "C_OWNER", "ID deines Discord accounts: " },
    { "C_OWNERTAG", "Tag deines Discord accounts (z.B. User#1234): "},
    { "C_LOGTODB", "Verifizierungen in lokaler Datenbank speichern? (Antworte mit y oder n): " },
    { "C_CAPTCHATYPE", "Sollen Text Nachrichten oder Bilder als Verifizierung benutzt werden? Antworte mit IMAGES oder TEXT: " },
    { "C_CMDALIAS", "Alias (schreibe NULL falls es so bleiben soll): " },
    { "C_CMDALLOWSELF", "Dir automatisch erlauben, den Command zu benutzen? (Antworte mit y oder n): " },
    { "C_CMDENABLE", "Command aktivieren? (Antworte mit y oder n): " },
    { "COMPILEINFO", "Dieses Programm wurde in C++ geschrieben und nutzt keine dritten Bibliotheken, daher kann es mit GCC ohne Probleme kompiliert werden." },
    { "DCAPTCHA_BUGS", "Der Quellcode kann auf DiscordCaptcha's offiziellen Repository gefunden werden (https://github.com/y21/discordcaptcha). Falls es Probleme gibt, solltest Du ein Issue auf dem Repository erstellen und das Problem so genau wie möglich beschreiben (oder es in einer Pull Request selber beheben)" },
    { "DCAPTCHA_LIB", "Der eigentliche Bot nutzt JavaScript und das NPM Modul \"discord.js\" um mit der Discord API zu kommunizieren."},
    { "BACKTOMENU", "Drücke ENTER um zum Menü zurückzukehren." },
    { "CFG_FINISHED", "Eine Datei mit dem Namen \"config.json\" wurde in dem selben Ordner erstellt. Ersetze sie durch die config.json Datei im src Ordner." },
    { "EXITPRG", "Drücke ENTER um das Programm zu beenden." },
    { "OFSTR_ERROR", "Ein Fehler ist beim Öffnen der config.json Datei aufgetreten." }
};


std::map<std::string, std::string> translations::en = {
    { "MENU_RUN_CFG", "Run config file generator" },
    { "MENU_CREDITS", "Credits & Disclaimer" },
    { "MENU_CHANGE_LANG", "Change Language" },
    { "MENU_EXIT", "Exit program" },
    { "C_BOT_TOKEN", "Bot token (can be found on Discord's Developer page): " },
    { "C_CLIENT_ID", "Client ID: " },
    { "C_PREFIX", "Prefix (what the bot reacts to, e.g. the exclamation mark in !verify): " },
    { "C_LOGCHAT", "The channel name where verification logs should be sent to: " },
    { "C_VERIFIEDROLE", "ID of the verified role: " },
    { "C_STREAMNAME", "The streaming game name (playing status): " },
    { "C_STREAMURL", "The URL of the stream (needs to be a valid twitch.tv one): " },
    { "C_EVALALWD", "Allow JS evaluations? Answer with y or n. (ONLY enable if experienced with JavaScript): " },
    { "C_OWNER", "The ID of your Discord account: " },
    { "C_OWNERTAG", "The tag of your Discord account (e.g. User#1234): "},
    { "C_LOGTODB", "Log verifications to a dedicated database hosted locally? Answer with y or n: " },
    { "C_CAPTCHATYPE", "Use text messages or images as captchas? Text messages are way less secure than images. Answer with IMAGES or TEXT: " },
    { "C_CMDALIAS", "Alias (type NULL if it should stay): " },
    { "C_CMDALLOWSELF", "Automatically allow you to use this command? (Answer with y or n): " },
    { "C_CMDENABLE", "Enable this command? (Answer with y or n): " },
    { "COMPILEINFO", "This program (the config file generator) has been written in plain C++ and does not use any third libraries, therefore it can be compiled without any issues using GCC." },
    { "DCAPTCHA_BUGS", "The source code can be found on DiscordCaptcha's official repository (https://github.com/y21/discordcaptcha). If there are any bugs, please make sure to open an issue or submit a pull request if you know how to fix that problem." },
    { "DCAPTCHA_LIB", "The actual bot (DiscordCaptcha) is using JavaScript and uses the npm package \"Discord.js\" to interact with the Discord API."},
    { "BACKTOMENU", "Hit ENTER to go back to the menu." },
    { "CFG_FINISHED", "A file named \"config.json\" has been created in this directory. Replace it with the one in the src directory which is located in DiscordCaptcha's home directory." },
    { "EXITPRG", "Hit ENTER to exit this program." },
    { "OFSTR_ERROR", "An error occured while trying to open/create a config.json file" }
};

std::string translations::getTranslation(char* langcode, std::string text) {
	if (*langcode == 0) {
		if (text == "MENU_RUN_CFG") return translations::en["MENU_RUN_CFG"];
		else if (text == "MENU_CREDITS") return translations::en["MENU_CREDITS"];
		else if (text == "MENU_CREDITS") return translations::en["MENU_CREDITS"];
		else if (text == "MENU_CHANGE_LANG") return translations::en["MENU_CHANGE_LANG"];
		else if (text == "MENU_EXIT") return translations::en["MENU_EXIT"];
		else if (text == "C_BOT_TOKEN") return translations::en["C_BOT_TOKEN"];
		else if (text == "C_CLIENT_ID") return translations::en["C_CLIENT_ID"];
		else if (text == "C_PREFIX") return translations::en["C_PREFIX"];
		else if (text == "C_LOGCHAT") return translations::en["C_LOGCHAT"];
		else if (text == "C_VERIFIEDROLE") return translations::en["C_VERIFIEDROLE"];
		else if (text == "C_STREAMNAME") return translations::en["C_STREAMNAME"];
		else if (text == "C_STREAMURL") return translations::en["C_STREAMURL"];
		else if (text == "C_EVALALWD") return translations::en["C_EVALALWD"];
		else if (text == "C_OWNER") return translations::en["C_OWNER"];
		else if (text == "C_OWNERTAG") return translations::en["C_OWNERTAG"];
		else if (text == "C_LOGTODB") return translations::en["C_LOGTODB"];
		else if (text == "C_CAPTCHATYPE") return translations::en["C_CAPTCHATYPE"];
		else if (text == "C_CMDALIAS") return translations::en["C_CMDALIAS"];
		else if (text == "C_CMDALLOWSELF") return translations::en["C_CMDALLOWSELF"];
		else if (text == "C_CMDENABLE") return translations::en["C_CMDENABLE"];
		else if (text == "COMPILEINFO") return translations::en["COMPILEINFO"];
		else if (text == "DCAPTCHA_BUGS") return translations::en["DCAPTCHA_BUGS"];
		else if (text == "DCAPTCHA_LIB") return translations::en["DCAPTCHA_LIB"];
		else if (text == "BACKTOMENU") return translations::en["BACKTOMENU"];
		else if (text == "CFG_FINISHED") return translations::en["CFG_FINISHED"];
		else if (text == "EXITPRG") return translations::en["EXITPRG"];
		else if (text == "OFSTR_ERROR") return translations::en["OFSTR_ERROR"];
	} else if(*langcode == 1) {
		if (text == "MENU_RUN_CFG") return translations::de["MENU_RUN_CFG"];
		else if (text == "MENU_CREDITS") return translations::de["MENU_CREDITS"];
		else if (text == "MENU_CREDITS") return translations::de["MENU_CREDITS"];
		else if (text == "MENU_CHANGE_LANG") return translations::de["MENU_CHANGE_LANG"];
		else if (text == "MENU_EXIT") return translations::de["MENU_EXIT"];
		else if (text == "C_BOT_TOKEN") return translations::de["C_BOT_TOKEN"];
		else if (text == "C_CLIENT_ID") return translations::de["C_CLIENT_ID"];
		else if (text == "C_PREFIX") return translations::de["C_PREFIX"];
		else if (text == "C_LOGCHAT") return translations::de["C_LOGCHAT"];
		else if (text == "C_VERIFIEDROLE") return translations::de["C_VERIFIEDROLE"];
		else if (text == "C_STREAMNAME") return translations::de["C_STREAMNAME"];
		else if (text == "C_STREAMURL") return translations::de["C_STREAMURL"];
		else if (text == "C_EVALALWD") return translations::de["C_EVALALWD"];
		else if (text == "C_OWNER") return translations::de["C_OWNER"];
		else if (text == "C_OWNERTAG") return translations::de["C_OWNERTAG"];
		else if (text == "C_LOGTODB") return translations::de["C_LOGTODB"];
		else if (text == "C_CAPTCHATYPE") return translations::de["C_CAPTCHATYPE"];
		else if (text == "C_CMDALIAS") return translations::de["C_CMDALIAS"];
		else if (text == "C_CMDALLOWSELF") return translations::de["C_CMDALLOWSELF"];
		else if (text == "C_CMDENABLE") return translations::de["C_CMDENABLE"];
		else if (text == "COMPILEINFO") return translations::de["COMPILEINFO"];
		else if (text == "DCAPTCHA_BUGS") return translations::de["DCAPTCHA_BUGS"];
		else if (text == "DCAPTCHA_LIB") return translations::de["DCAPTCHA_LIB"];
		else if (text == "BACKTOMENU") return translations::de["BACKTOMENU"];
		else if (text == "CFG_FINISHED") return translations::de["CFG_FINISHED"];
		else if (text == "EXITPRG") return translations::de["EXITPRG"];
		else if (text == "OFSTR_ERROR") return translations::de["OFSTR_ERROR"];
	} else return "";
}
