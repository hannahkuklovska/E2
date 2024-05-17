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

pomocou _Gaussovej eliminačnej metódy_
**input matrix:**

$$
\begin{bmatrix}
a\_{11} & a\_{12} & a\_{13} & 1 & 0 & 0 \\\
a\_{21} & a_{22} & a_{23} & 0 & 1 & 0 \\\
a\_{31} & a\_{32} & a\_{33} & 0 & 0 & 1 \\\
\end{bmatrix}
$$

**identity matrix:**

$$
\begin{array}{ccc}
1 & 0 & 0 \\\
0 & 1 & 0 \\\
0 & 0 & 1 \\\
\end{array}
$$

**augmented matrix:**

$$
\begin{bmatrix}
a\_{11} & a\_{12} & a\_{13} \\\
a\_{21} & a\_{22} & a\_{23} \\\
a\_{31} & a\_{32} & a\_{33} \\\
\end{bmatrix}
$$

- **input_matrix:** Vstupná matica, ktorej inverznú maticu chceme vypočítať.
- **návratová hodnota:** Inverzná matica k vstupnej matici, alebo NULL v prípade neúspechu (napríklad ak vstupná matica nie je invertovateľná).
- funkcia predpokladá, že vstupná matica je _štvorcová_ (rovnaký počet riadkov a stĺpcov).
- v prípade, že vstupná matica nie je invertovateľná, funkcia vráti **NULL**.
- v prípade úspechu vráti funkcia inverznú maticu k vstupnej matici.
