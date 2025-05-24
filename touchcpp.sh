#!/bin/bash

if [ -z "$1" ]; then
  echo "Usage : $0 NomDuFichier (sans extension)"
  exit 1
fi

NOM="$1"
CPP_FILE="${NOM}.cpp"
HPP_FILE="${NOM}.hpp"
INCLUDE_GUARD=$(echo "${NOM}_HPP" | tr '[:lower:]' '[:upper:]')
CLASS_NAME="${NOM^}"
USER="$(whoami)"
DATE_CREATED=$(date +"%Y/%m/%d %H:%M:%S")
DATE_UPDATED="$DATE_CREATED"  # Au départ même date

generate_42_header() {
  local author="vsyutkin"
  local email="vsyutkin@student.42mulhouse.fr"
  local created_date
  local updated_date

  created_date=$(date +"%Y/%m/%d %H:%M:%S")
  updated_date="$created_date"

  cat <<EOF
/* ************************************************************************** */
/*                                                                      42.fr */
/*   By: $author <$email>                            */
/*                                                                            */
/*   Created: $created_date by $author                                 */
/*                                                                            */
/* ************************************************************************** */
EOF
}

# Bannière ASCII d'ornement, tu peux la garder ou pas
BANNER='/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */
/* @#######_#_##_######_____########____########______##########_#_##_######@ */
/* @######/\| |/\\####/ ____|######/ __ \######|  ____|########/\| |/\|#####@ */
/* @######\     /####| |##########| |##| |#####| |__###########\     /######@ */
/* @#####|_     _|###| |##########| |##| |#####|  __|#########|_     _|#####@ */
/* @######/ , . \####| |____###_##| |__| |##_##| |#######_#####/ , . \######@ */
/* @######\/|_|\/#####\_____|#(_)##\____/##(_)#|_|######(_)####\/|_|\/######@ */
/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ */'

SEPARATOR='/******************************************************************************/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/*-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._*/
/*-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-""-._.-"*/
/******************************************************************************/'

# Génère fichier .hpp
{
generate_42_header "${HPP_FILE}" "$DATE_CREATED" "$DATE_UPDATED"
echo
cat <<EOF
#ifndef $INCLUDE_GUARD
#define $INCLUDE_GUARD

class $CLASS_NAME
{
	private:										// Private members

	protected:										// Protected members for inheritance

	public:
		$CLASS_NAME();                                	// Default constructor
		$CLASS_NAME(const $CLASS_NAME &other);         	// Copy constructor
		$CLASS_NAME &operator=(const $CLASS_NAME &other); // Assignment operator
		~$CLASS_NAME();                                	// Destructor
};

#endif // $INCLUDE_GUARD
EOF
} > "$HPP_FILE"

# Génère fichier .cpp
{
generate_42_header "${CPP_FILE}" "$DATE_CREATED" "$DATE_UPDATED"
echo
cat <<EOF
#include "$HPP_FILE"

$BANNER
// Default constructor
$CLASS_NAME::$CLASS_NAME()
{
	;
}

// Copy constructor
$CLASS_NAME::$CLASS_NAME(const $CLASS_NAME &other)
{
	;
}

// Assignment logic
$CLASS_NAME &$CLASS_NAME::operator=(const $CLASS_NAME &other)
{
	if (this != &other)
	{
		;
	}
	return *this;
}

// Destructor
$CLASS_NAME::~$CLASS_NAME()
{
	;
}

$SEPARATOR
//	Private methods

/* ************************************************************************** */
//	Protected methods

/* ************************************************************************** */
//	Public methods
EOF
} > "$CPP_FILE"

echo "Fichiers orthodoxes créés : $CPP_FILE, $HPP_FILE"
