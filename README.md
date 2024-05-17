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
  \[
  \left[
  \begin{array}{ccc|ccc}
  a_{11} & a_{12} & a_{13} & 1 & 0 & 0 \\
  a_{21} & a_{22} & a_{23} & 0 & 1 & 0 \\
  a_{31} & a_{32} & a_{33} & 0 & 0 & 1 \\
  \end{array}
  \right]
  \]

identity matrix
\[
\begin{array}{ccc}
1 & 0 & 0 \\
0 & 1 & 0 \\
0 & 0 & 1 \\
\end{array}
\]

augmented matrix
\[
\begin{bmatrix}
a*{11} & a*{12} & a*{13} \\
a*{21} & a*{22} & a*{23} \\
a*{31} & a*{32} & a\_{33} \\
\end{bmatrix}
\]

- input_matrix: Vstupná matica, ktorej inverznú maticu chceme vypočítať.
- Návratová hodnota: Inverzná matica k vstupnej matici, alebo NULL v prípade neúspechu (napríklad ak vstupná matica nie je invertovateľná).
- Funkcia predpokladá, že vstupná matica je štvorcová (rovnaký počet riadkov a stĺpcov).
- V prípade, že vstupná matica nie je invertovateľná, funkcia vráti NULL.
- V prípade úspechu vráti funkcia inverznú maticu k vstupnej matici.
