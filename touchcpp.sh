#!/bin/bash

if [ "$#" -lt 1 ]; then
  echo "Usage : $0 NomClasse1 [NomClasse2 ...]"
  exit 1
fi

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

for NOM in "$@"; do
  CPP_FILE="${NOM}.cpp"
  HPP_FILE="${NOM}.hpp"
  INCLUDE_GUARD=$(echo "${NOM}_HPP" | tr '[:lower:]' '[:upper:]')
  CLASS_NAME="${NOM^}"
  DATE_CREATED=$(date +"%Y/%m/%d %H:%M:%S")
  DATE_UPDATED="$DATE_CREATED"

  # Génère .hpp
  {
    generate_42_header
    echo
    cat <<EOF
#ifndef $INCLUDE_GUARD
#define $INCLUDE_GUARD

# include "../terminal_colors.hpp"
# include <iostream>

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

  # Génère .cpp
  {
    generate_42_header
    echo
    cat <<EOF
#include "$HPP_FILE"

$BANNER
// Default constructor
$CLASS_NAME::$CLASS_NAME()
{
	std::cout << TERMINAL_GREEN << "\tDefault constructor $CLASS_NAME called" << TERMINAL_RESET << std::endl;
}

// Copy constructor
$CLASS_NAME::$CLASS_NAME(const $CLASS_NAME &other)
{
	std::cout << TERMINAL_GREEN << "\tCopy constructor $CLASS_NAME called" << TERMINAL_RESET << std::endl;
}

// Assignment logic
$CLASS_NAME &$CLASS_NAME::operator=(const $CLASS_NAME &other)
{
	if (this != &other)
	{
		std::cout << TERMINAL_GREEN << "\tAssignation operator $CLASS_NAME called" << TERMINAL_RESET << std::endl;
	}
	return (*this);
}

// Destructor
$CLASS_NAME::~$CLASS_NAME()
{
	std::cout << TERMINAL_GREEN << "\tDestructor $CLASS_NAME called" << TERMINAL_RESET << std::endl;
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
done