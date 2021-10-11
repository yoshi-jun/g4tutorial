# Ubuntu start manual
## need packages
* build-essential
* tcsh
* zsh
* sudo
* make
* vim
* git
* cmake
* libboost-dev
* libexpat1-dev
* libxerces-c-dev
* qtbase5-dev
* qttools5-dev-tools
* qt5-default
* libx11-dev
* libxmu-dev
## command ?
**done yet**
~~~
sudo dpkg-reconfigure dash ->no
~~~

## install google chrome
get public key from URL and register it
~~~
wget -q -0 - https://dl-ssl.google.com/linux/linux_singning_key.pub | sudo apt-key add -
~~~
update apt package list
~~~
apt update
~~~
install google-chrome
~~~
apt install google-chrome-stable
~~~

## install vscode
~~~
sudo snap install --classic　code
~~~
## install gitkraken
~~~
sudo snap install gitkraken --classic
~~~
## Add file to home directory
~~~
cat ~/.g4session
tcsh
~~~