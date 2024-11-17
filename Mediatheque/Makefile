# Nom de l'exécutable
EXEC = main

# Répertoires des fichiers sources et d'inclusion
SRC_DIR = src
INCLUDE_DIR = include

# Fichiers source nécessaires pour le test
SRCS = main.cpp $(SRC_DIR)/CD.cpp $(SRC_DIR)/Mediatheque.cpp

# Fichiers objets correspondants
OBJS = $(SRCS:.cpp=.o)

# Options du compilateur
CXX = g++
CXXFLAGS = -Wall -Wextra -I$(INCLUDE_DIR)

# Règle par défaut (cible principale)
$(EXEC): $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS)

# Règle de compilation des fichiers .o à partir des fichiers .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS) $(EXEC)

