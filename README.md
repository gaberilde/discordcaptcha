<img src="https://image.ibb.co/gEN0oR/discord_banner.png"><br/>
A Captcha verification bot based on Discord.js.

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/ba341e35d2c84bc0a0adc6a2ae2f4e1c)](https://app.codacy.com/app/y21/discordcaptcha?utm_source=github.com&utm_medium=referral&utm_content=y21/discordcaptcha&utm_campaign=badger)

You can find a detailed tutorial <a href="https://y21.gitbooks.io/discordcaptcha/content/">here</a>.<br/>
Feel free to join our <a href="https://discord.gg/955naZw">discord server</a> for live support.

## Setup procedure
DiscordCaptcha requires NodeJS 8.0+. Install it <a href="https://nodejs.org/en/download/package-manager/">here</a>.<br />
To install all required NPM-Modules, run the install script in `~/setup/` (.sh or .bat file depends on your operating system) (or `npm install` <b>in bots' directory</b> if both don't work.) (Click <a href="https://discordjs.guide/#/preparations/?id=installing-nodejs">here</a> for a detailed installation tutorial on how to install nodejs)<br/><br/>
For now, make sure the bot is only in one guild.
The config file is located in `~/src/`. Get your Token from <a href="https://discordapp.com/developers/applications/me">here</a>.

## Config-file generator
Newer versions of DiscordCaptcha have a config-file generator. It is written in C++ and needs to be compiled if you want to run it. If you don't have a compiler, I recommend the GCC compiler. The file is located in `~/cfg_gen/`.

## Additional commands
> Command names can be changed in the config file.
```js
/**
* Snowflake: ID
**/
!blockUser <Snowflake> // Blocks a User ID. If the User sends a message to the guild, he'll get kicked.
!removeBlock <Snowflake> // Removes a User ID from the blacklist. User can write again without getting kicked.
!clear <Amount of messages> // Clears an amount of messages, up to 100
!version // The current version and the latest version
!create-role // Creates the verification role
```

## Changing captcha type
Discordcaptcha offers you two captcha types: first, images as captchas and second, normal text messages.
It's up on you whether you want images or text. Notice, that images are **way** harder to bypass than normal text messages.<br/>
The default type is `image`. To edit the type, you change the value of key `captchaType` in `~/src/config.json` to either `image`or `text`.<br/>


## API related commands
> The command is - as mentioned above - changable. These are the default command names.
Also commands can be turned off by changing `enabled` to `false`.
```js
!queries // Current query
!querydelete // Deletes the query (should be executed every 2 or 3 weeks)
!purgelogs // Purges the logs
!logs // Get logs
!makerole // Creates a 'verified' role
!unverify // Lets the user unverify
```
<b>Note: </b>If you want to use these commands, you have to put your tag into the `contributors` array.
<img src="https://i.imgur.com/Pw4MnB0.png"></img>

## Dealing with SQL(ite)
Blocked users, logs and queries are stored in a database which is located in `~/src/db.sqlite`. If you want to read data from it, I recommend <a href="http://sqlitebrowser.org/">SQLite DB Browser</a> (<a href="https://nightlies.sqlitebrowser.org/latest/">Nightly</a>).
After the installation, you're able to open the database by clicking 'open database' in the program.

### Using the minified file
In case you don't want to edit the main code, you can delete the `index.js` file locally and rename `index.min.js` to `index.js`.
An other option is to change the value of `main` key of the package.json file from `index.js` to `index.min.js`.
What this does is letting you to type `node .` in the command prompt instead of `node <path>`

## Tips
• Look at the wiki for some fixes.<br/>
• Contact me via discord. (y21#0909 | ID: 312715611413413889)<br/>
• Open a Pull Request/Issue