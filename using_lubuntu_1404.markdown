#using_lubuntu_1404.markdown
Lubuntu 14.04 LTS are the used workstation (Intel Duo Core 1.86GHz, 2GB) in the company since year 2014. In this note, experiences of using Lubuntu 14.04 LTS are recorded.

Q: How to setup software updater behind a proxy?

A: Edit /etc/apt/apt.conf. Add the following line and reboot.

Acquire::http::proxy "http://proxy.avermedia.com:8080/";

[ref](http://askubuntu.com/questions/288501/how-to-set-proxy-settings-in-ubuntu-software-center)

Q: How to setup system-wide proxy?

A: Run the scripts provided by the reference. And reboot.

[ref](http://askubuntu.com/questions/150210/how-do-i-set-systemwide-proxy-servers-in-xubuntu-lubuntu-or-ubuntu-studio)

Q: How to use github behind a proxy in the company?

A: export https_proxy=proxy.avermedia.com:8080.

[ref](http://stackoverflow.com/questions/5529218/how-to-use-git-behind-a-proxy)
