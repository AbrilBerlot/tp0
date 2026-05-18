# TP0 — Prueba de Iniciación de los Magios 

> Trabajo Práctico N°0 — Fundamentos de la Programación  
> Universidad de Buenos Aires (UBA) — 1° cuatrimestre 2026  
> **Nota obtenida: 10** 

## Descripción

Programa de consola en **C** que simula la prueba de iniciación a la sociedad secreta de los Magios de Springfield. El usuario responde 4 preguntas rituales y obtiene un puntaje final que determina su rango dentro de la logia.

## Funcionalidades

- Validación estricta de cada entrada del usuario (sin avanzar hasta respuesta válida)
- Pregunta 1: múltiple opción con máximo 3 intentos y penalización por error
- Pregunta 2: guardar o no el secreto de los Magios (impacto alto en puntaje)
- Pregunta 3: fecha de nacimiento en formato `yyyy/mm` con validación de rango y mayoría de edad
- Pregunta 4: cantidad de donas a sacrificar (0–12) con tabla de puntaje escalonada
- Cálculo de puntaje final y mensaje de resultado entre guiones

## Resultados posibles

| Puntaje        | Resultado         |
|----------------|-------------------|
| < 0            | `-RECHAZADO-`     |
| 0 – 150        | `-ASPIRANTE-`     |
| 151 – 250      | `-MAGIO NOVATO-`  |
| 251 – 349      | `-MAGIO-`         |
| 350 o más      | `-LIDER SUPREMO-` |

## Compilación y ejecución

```bash
gcc magios.c -Wall -Werror -Wconversion -std=c99 -o magios
./magios
```

## Conceptos aplicados

- Tipos de datos simples (`int`, `char`, `bool`)
- Estructuras de control (`if`, `while`)
- Modularización: cada pregunta tiene sus propias funciones de validación, ingreso y puntaje
- Buenas prácticas: constantes con nombre descriptivo, pre/post condiciones, sin variables globales

## Materia

**Fundamentos de la Programación** — Cátedra Méndez  
Ingeniería Informática — FIUBA  
Sitio de la cátedra: [fundamendez.com.ar](https://fundamendez.com.ar)
