// 1. O que é um arquivo .h (header file)
// Em C, os arquivos de cabeçalho (.h) servem para:
// Declarar protótipos de funções (as assinaturas delas, sem a implementação).
// Definir constantes (#define, const, enum).
// Criar estruturas, tipos (typedef) ou macros.
// Facilitar a organização do código, separando o que o programa oferece (interface) de como ele faz (implementação em .c).

// em C ate da pra fazer um #include "area.c", mas n é recomendavel, pq qnd vc faz isso o compilador compila muita coisa de uma vez e mistura o que pode dar erro se muitos codigos usarem o msm import
// ent é recomendado vc criar um arquivo area.c e um header pra ele, passando apenas o que seria uma especie de interface das funcoes do arquivo area.c


// FAZENDO UM PARALELO isso seria a msm coisa que um controller e um service, em que o controller é apenas uma forma de modularizar a chamada, isolando a logica, presente no service

// ent nessa questao a gente cria um arquivo que tem as funcoes que terao na area.c mas sem implementa-las

#ifndef AREA_H
#define AREA_H

float area_quadrado(float l);
float area_triangulo(float b, float h);
float area_circulo(float r);

#endif 

// como funciona: o #ifndef quer dizer if not defined, #define AREA_H, isso define o comeco do que vc vai definir como AREA_H, ai qnd acabar vc fecha com #endif