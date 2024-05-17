# E2

## Popis projektu

Tento projekt implementuje základnú prácu s maticami v jazyku C. Obsahuje funkcie na vytváranie, ukladanie, načítavanie, tlačenie a operácie s maticami, vrátane násobenia matíc a invertovania matíc.

## Štruktúra MAT

Definícia štruktúry MAT, ktorá predstavuje maticu:

```c
typedef struct
{
     unsigned int rows;   // počet riadkov matice
     unsigned int cols;   // počet stĺpcov matice
     float *elem;         // pole prvkov matice
} MAT;
```

## Inverzná matica

Táto funkcia vypočíta inverznú maticu k zadanej matici.

```c
MAT *mat_invert(MAT *input_matrix);
```

### Popis

- pomocou Gaussovej eliminačnej metódy
  input matrix:
  | a11 a12 a13 |
  | a21 a22 a23 |
  | a31 a32 a33 |

identity matrix
| 1 0 0 |
| 0 1 0 |
| 0 0 1 |

augmented matrix
| a11 a12 a13 | 1 0 0 |
| a21 a22 a23 | 0 1 0 |
| a31 a32 a33 | 0 0 1 |

- input_matrix: Vstupná matica, ktorej inverznú maticu chceme vypočítať.
- Návratová hodnota: Inverzná matica k vstupnej matici, alebo NULL v prípade neúspechu (napríklad ak vstupná matica nie je invertovateľná).
- Funkcia predpokladá, že vstupná matica je štvorcová (rovnaký počet riadkov a stĺpcov).
- V prípade, že vstupná matica nie je invertovateľná, funkcia vráti NULL.
- V prípade úspechu vráti funkcia inverznú maticu k vstupnej matici.
