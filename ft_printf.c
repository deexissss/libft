/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjehaes <tjehaes@student.42luxembourg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:33:25 by tjehaes           #+#    #+#             */
/*   Updated: 2024/03/15 15:06:33 by tjehaes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(va_list args, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_printchar(va_arg(args, int));
	else if (c == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_printptr(va_arg(args, unsigned long long));
	else if (c == 'd')
		len += ft_printdecimal(va_arg(args, int));
	else if (c == 'i')
		len += ft_printint(va_arg(args, int));
	else if (c == 'u')
		len += ft_printunsigned(va_arg(args, int));
	else if (c == 'x')
		len += ft_print_hexa(va_arg(args, unsigned long), c);
	else if (c == 'X')
		len += ft_print_hexa(va_arg(args, unsigned long), c);
	else if (c == '%')
		len += ft_printchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			len += check_type(args, str[i + 1]);
			i++;
		}
		else
			len += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("=== Test de ft_printf ===\n");
	
	// Test des différents types de spécificateurs
	printf("Test des spécificateurs :\n");
	printf("Caractère : %c\n", 'A');
	ft_printf("Caractère : %c\n", 'A');
	
	printf("Chaîne : %s\n", "Bonjour");
	ft_printf("Chaîne : %s\n", "Bonjour");
	
	printf("Pointeur : %p\n", (void *)0x12345678);
	ft_printf("Pointeur : %p\n", (void *)0x12345678);
	
	printf("Entier : %d\n", 123);
	ft_printf("Entier : %d\n", 123);
	
	printf("Entier : %i\n", -456);
	ft_printf("Entier : %i\n", -456);
	
	printf("Entier non signé : %u\n", 789);
	ft_printf("Entier non signé : %u\n", 789);
	
	printf("Hexadécimal : %x\n", 255);
	ft_printf("Hexadécimal : %x\n", 255);

	printf("Hexadécimal : %x\n", -255);
	ft_printf("Hexadécimal : %x\n", -255);

	printf("Hexadécimal : %X\n", 255);
	ft_printf("Hexadécimal : %X\n", 255);

	printf("Hexadécimal : %X\n", -255);
	ft_printf("Hexadécimal : %X\n", -255);

	printf("Pourcentage : %%\n");
	ft_printf("Pourcentage : %%\n");
	
	// Test d'un mélange de spécificateurs
	printf("\nTest d'un mélange de spécificateurs :\n");
	printf("Chaîne : %s, Entier : %d, Caractère : %c\n", "Hello", -123, 'A');
	ft_printf("Chaîne : %s, Entier : %d, Caractère : %c\n", "Hello", -123, 'A');
	
	// Test de cas particuliers
	printf("\nTest de cas particuliers :\n");
	printf("Chaîne vide : %s\n", "");
	ft_printf("Chaîne vide : %s\n", "");

	printf("Entier nul : %d\n", 0);
	ft_printf("Entier nul : %d\n", 0);
	
	printf("Entier négatif : %d\n", -789);
	ft_printf("Entier négatif : %d\n", -789);
	
	return (0);
}*/
/*
#include <stdio.h>
#include <stdarg.h>

// Fonction pour comparer les résultats
int	check_results(const char *format, ...)
{
	va_list	args;
	va_start(args, format);
	int result_printf, result_ft_printf;

    // Utilisez printf pour obtenir le résultat attendu
    printf("\033[0mprintf: ");
    result_printf = vprintf(format, args); // Stocke le résultat de printf
    printf("\n");

    // Réinitialiser l'argument de la liste
    va_end(args);
    va_start(args, format);

    // Utilisez ft_printf pour obtenir le résultat obtenu par votre fonction
    printf("\033[0mft_printf: ");
    result_ft_printf = vprintf(format, args); // Stocke le résultat de ft_printf
    printf("\n");

    va_end(args);

    // Comparez les résultats
    if (result_printf == result_ft_printf) {
        printf("\033[32m   Test: OK\n"); // OK en vert
        return 1; // Retourne 1 si les résultats sont les mêmes
    } else {
        printf("\033[31m   Test: KO\n"); // KO en rouge
        return 0; // Retourne 0 si les résultats sont différents
    }
}

// Fonction pour exécuter tous les tests
void run_tests() {
    printf("\033[33m=== Test de ft_printf ===\n\n");

    // Test des différents types de spécificateurs
    printf("\033[33mTest des spécificateurs :\n");
    check_results("Caractère : %c\n", 'a');
    check_results("Chaîne : %s\n", "Bonjour");
    check_results("Pointeur : %p\n", (void *)0x12345678);
    check_results("Entier : %d\n", 123);
    check_results("Entier : %i\n", -456);
    check_results("Entier non signé : %u\n", 78);
    check_results("Hexadécimal : %x\n", 255);
    check_results("Hexadécimal : %x\n", -255);
    check_results("Hexadécimal : %X\n", 255);
    check_results("Hexadécimal : %X\n", -255);
    check_results("Pourcentage : %%\n");

    // Test d'un mélange de spécificateurs
    printf("\033[33m\n Test d'un mélange de spécificateurs :\n");
    check_results("Chaîne : %s, Entier : %d, Caractère : %c\n",
		    "Hello", -123, 'A');

    // Test de cas particuliers
    printf("\033[33m\nTest de cas particuliers :\n"); // Jaune pour l'en-tête
    check_results("Chaîne vide : %s\n", "");
    check_results("Entier nul : %d\n", 0);
    check_results("Entier négatif : %d\n", -789);
}

int main(void) {
    run_tests();
    return 0;
}*/
