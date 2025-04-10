#!/bin/bash

# Vérifie si un nom a été fourni
if [ -z "$1" ]; then
  echo "Usage : $0 NomDuFichier (sans extension)"
  exit 1
fi

NOM="$1"
CPP_FILE="${NOM}.cpp"
HPP_FILE="${NOM}.hpp"
INCLUDE_GUARD=$(echo "${NOM}_HPP" | tr '[:lower:]' '[:upper:]')

# Création du fichier .hpp avec la forme canonique
cat <<EOF > "$HPP_FILE"
#ifndef $INCLUDE_GUARD
#define $INCLUDE_GUARD

class ${NOM^} {
private:
    // Private members

protected:
    // Protected members for inheritance

public:
    ${NOM^}();                                 // Default constructor
    ${NOM^}(const ${NOM^} &other);             // Copy constructor
    ${NOM^} &operator=(const ${NOM^} &other);  // Assignment operator
    ~${NOM^}();                                // Destructor
};

#endif // $INCLUDE_GUARD
EOF

# Création du fichier .cpp avec les définitions de la forme canonique
cat <<EOF > "$CPP_FILE"
#include "${HPP_FILE}"

${NOM^}::${NOM^}() {
    // Default constructor
}

${NOM^}::${NOM^}(const ${NOM^} &other) {
    // Copy constructor
}

${NOM^} &${NOM^}::operator=(const ${NOM^} &other) {
    if (this != &other) {
        // Assignment logic
    }
    return *this;
}

${NOM^}::~${NOM^}() {
    // Destructor
}
EOF

echo "Fichiers orthodoxes créés : $CPP_FILE, $HPP_FILE"
