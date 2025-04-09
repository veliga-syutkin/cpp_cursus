#!/bin/bash

# Vérifie si un nom a été fourni
if [ -z "$1" ]; then
  echo "Usage : $0 NomDuFichier (sans extension)"
  exit 1
fi

NOM="$1"
CPP_FILE="${NOM}.cpp"
HPP_FILE="${NOM}.hpp"

# Création du fichier .hpp avec squelette
cat <<EOF > "$HPP_FILE"
#ifndef ${NOM^^}_HPP
#define ${NOM^^}_HPP

class ${NOM^} {
public:
    ${NOM^}();
    ~${NOM^}();

private:

};

#endif // ${NOM^^}_HPP
EOF

# Création du fichier .cpp avec squelette
cat <<EOF > "$CPP_FILE"
#include "${HPP_FILE}"

${NOM^}::${NOM^}() {
    // Constructeur
}

${NOM^}::~${NOM^}() {
    // Destructeur
}
EOF

echo "Fichiers créés : $CPP_FILE, $HPP_FILE"
