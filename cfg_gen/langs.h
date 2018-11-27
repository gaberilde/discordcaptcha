namespace translations
{
enum LANG { DE, EN };
extern std::map<std::string, std::string> en;
extern std::map<std::string, std::string> de;
std::string getTranslation(char*, std::string);
}
