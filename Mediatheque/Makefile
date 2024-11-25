# Nom de l'exécutable
EXEC = main

# Répertoires des fichiers sources, d'inclusion et de build
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build

# Fichiers source nécessaires pour le projet
SRCS = main.cpp \
       $(SRC_DIR)/CD.cpp \
       #$(SRC_DIR)/Mediatheque.cpp \
       #$(SRC_DIR)/Livre.cpp \
       $(SRC_DIR)/Film.cpp

# Fichiers objets correspondants (placés dans le répertoire build)
OBJS = $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(notdir $(SRCS)))

# Options du compilateur
CXX = g++
CXXFLAGS = -Wall -Wextra -I$(INCLUDE_DIR)

# Règle par défaut (cible principale)
$(EXEC): $(OBJS)
	$(CXX) -o $(EXEC) $(OBJS)

# Règle de compilation des fichiers .o à partir des fichiers .cpp
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: main.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -rf $(BUILD_DIR)/*.o $(EXEC)
