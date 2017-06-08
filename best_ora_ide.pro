##-------------------------------------------------
##
## Project created by QtCreator 2017-02-10T14:22:45
##
##-------------------------------------------------

TEMPLATE = subdirs
CONFIG+=ordered
SUBDIRS += source\
   tests
app.depends = src
tests.depends = src

