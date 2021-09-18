# CMakeList.txt : projet CMake pour Listes, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

project ("Listes")

# Ajoutez une source à l'exécutable de ce projet.
add_executable (Listes  "list.hpp" "node.hpp" "main.cpp")

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
