/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deneme.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:44:00 by eakman            #+#    #+#             */
/*   Updated: 2024/10/30 20:44:00 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <math.h>

int main(){
    double a = 5;
    double b = 3.0;

    if (a == b)
        printf("a and b are equal\n");
    else
        printf("a and b are not equal\n");

    double epsilon = 1e-9;
    if (fabs(a - b) < epsilon)
        printf("a and b are equal\n");
    else
        printf("a and b are not equal\n");
}