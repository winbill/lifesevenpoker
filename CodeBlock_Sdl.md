# Introduction #

installer les librairies Sdl pour compiler avec c::b


## Details ##

  1. ouvrir le gestionnaire de paquet synaptique
  1. faire une recherche sur libsdl1.2
  1. installer les paquets suivants : libsdl1.2-dev libsdl1.2debian

## installation des add-ons ##

  1. ouvrir le gestionnaire de paquet synaptique
  1. rechercher libsdl-"addon" par exemple (libsdl-image libsdl-ttf)
  1. installer la librairie ainsi que sa version de dev

## linker la lib ##

  1. Dans code::blocks, project -> build options -> Linker -> Link libraries -> add . Tapez le nom du module (ex : SDL\_image avec un underscore et sans le préfixe "lib").