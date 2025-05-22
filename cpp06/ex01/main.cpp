/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eakman <arcemirhanakman@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:58:44 by eakman            #+#    #+#             */
/*   Updated: 2025/05/22 00:58:44 by eakman           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main() {
    Data original;
    original.id = 42;
    original.name = "SerializedObject";

    uintptr_t raw = Serializer::serialize(&original);
    Data* copy = Serializer::deserialize(raw);

    std::cout << "Original address: " << &original << "\n";
    std::cout << "Serialized int:   " << raw << "\n";
    std::cout << "Deserialized ptr: " << copy << "\n";
    std::cout << "copy->id: " << copy->id << ", copy->name: " << copy->name << "\n";

    return 0;
}
