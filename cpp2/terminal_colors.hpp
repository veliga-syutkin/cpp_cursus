/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_colors.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyutkin <vsyutkin@student.42mulhouse.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 10:08:43 by vsyutkin          #+#    #+#             */
/*   Updated: 2025/04/10 10:12:17 by vsyutkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_COLORS_HPP
#define TERMINAL_COLORS_HPP

// Reset
#define TERMINAL_RESET        "\033[0m"

// Regular Colors
#define TERMINAL_BLACK        "\033[30m"
#define TERMINAL_RED          "\033[31m"
#define TERMINAL_GREEN        "\033[32m"
#define TERMINAL_YELLOW       "\033[33m"
#define TERMINAL_BLUE         "\033[34m"
#define TERMINAL_MAGENTA      "\033[35m"
#define TERMINAL_CYAN         "\033[36m"
#define TERMINAL_WHITE        "\033[37m"

// Bold
#define TERMINAL_BOLD_BLACK   "\033[1;30m"
#define TERMINAL_BOLD_RED     "\033[1;31m"
#define TERMINAL_BOLD_GREEN   "\033[1;32m"
#define TERMINAL_BOLD_YELLOW  "\033[1;33m"
#define TERMINAL_BOLD_BLUE    "\033[1;34m"
#define TERMINAL_BOLD_MAGENTA "\033[1;35m"
#define TERMINAL_BOLD_CYAN    "\033[1;36m"
#define TERMINAL_BOLD_WHITE   "\033[1;37m"

// Underline
#define TERMINAL_UNDER_BLACK   "\033[4;30m"
#define TERMINAL_UNDER_RED     "\033[4;31m"
#define TERMINAL_UNDER_GREEN   "\033[4;32m"
#define TERMINAL_UNDER_YELLOW  "\033[4;33m"
#define TERMINAL_UNDER_BLUE    "\033[4;34m"
#define TERMINAL_UNDER_MAGENTA "\033[4;35m"
#define TERMINAL_UNDER_CYAN    "\033[4;36m"
#define TERMINAL_UNDER_WHITE   "\033[4;37m"

// Background Colors
#define TERMINAL_BG_BLACK     "\033[40m"
#define TERMINAL_BG_RED       "\033[41m"
#define TERMINAL_BG_GREEN     "\033[42m"
#define TERMINAL_BG_YELLOW    "\033[43m"
#define TERMINAL_BG_BLUE      "\033[44m"
#define TERMINAL_BG_MAGENTA   "\033[45m"
#define TERMINAL_BG_CYAN      "\033[46m"
#define TERMINAL_BG_WHITE     "\033[47m"

#endif // TERMINAL_COLORS_HPP