
# Dynamic Programming cses problemset


## Dice Combinations (Ejercicio 5)

Sea $dp[n]$ el número de formas de construir una suma $n$ lanzando un dado una o más veces. Definimos $dp[n]$ recursivamente como sigue:

$$
dp[n]= 
\begin{cases}
1 & \quad \text{when $n=0$}\\ 
\sum_{i=1}^{\min(n,6)} dp[n - i] & \quad \text{otherwise}
\end{cases}
$$

## Minimizing Coins
Tenemos un sistema de monedas $C=[c_1,c_2,...c_n]$ de tamaño $n$. Sea $OPT(x)$ la mínima cantidad de monedas requeridas para formar un monto $x$. Definimos $OPT(x)$ recursivamente como sigue:

$$
OPT(x)= 
\begin{cases}
0 & \quad \text{when $x=0$}\\ 
\min_{1\leq i\leq n} OPT(x- c_i)+1 & \quad \text{otherwise}
\end{cases}
$$

Subestructura óptima:

Suponga que $X$ (lista de monedas) es una solución óptima para el problema.
Sea $Y$ 



## Removing Digits

Sea $n=\overline{d_1d_2...d_j}$ un número con $j$ dígitos.

Sea $OPT(n)$ la cantidad mínima de pasos para hacer 0 el número $n$ sustrayendo uno de sus dígitos. Definimos $OPT(n)$ recursivamente como sigue:

$$
OPT(n)=
\begin{cases}
1 & \quad \text{when $n$ has only one digit}\\ 
\min_{1\leq i \leq j} (OPT(n - d_i))+ 1 & \quad \text{otherwise}
\end{cases}
$$

Subestructura óptima:


## Grid Paths

Sea $M[0…n-1,0…n-1]$  una cuadrícula $n\times n$.

Sea $dp[i,j]$  el número de caminos posibles para llegar desde $M[i,j]$ a $M[n-1,n-1]$ con $0\leq i\leq j \leq n$. Definimos $dp[i,j]$ recursivamente como sigue:

$$
dp[i,j]=
\begin{cases}
0 & \quad \text{when $i=n ∨ j=n ∨ M[i,j]='*'$}\\ 
1 & \quad \text{when $i=n-1 ∧j=n-1$}\\
dp[i + 1,j] + dp[i,j + 1] & \quad \text{otherwise}
\end{cases}
$$

## Rectangle Cutting

Sea $OPT(n,m)$ la mínima cantidad de movimientos para cortar un rectángulo $n \times m$ en cuadrados. Definimos $OPT(n,m)$ recursivamente como sigue:

$$
OPT(n,m)=
\begin{cases}
\infty & \quad \text{when $n<1 ∨ m<1$}\\ 
0 & \quad \text{when $n=m$}\\
\min_{1\leq k<n}^{1\leq q<m} (OPT(k,m) + OPT(n - k,m),OPT(n,q)+OPT(n,m-q)) & \quad \text{otherwise}
\end{cases}
$$

## Rod Cutting (Cormen)

Sea $OPT(n)$ el máximo beneficio de cortar y vender las piezas de una varilla de longitud $n$. Sea $p_i$ el precio de venta de una varilla de longitud $i$ con $1\leq i \leq n$. Definimos $OPT(n)$ recursivamente como sigue:

$$
OPT(n)=
\begin{cases}
0 & \quad \text{when $n=0$}\\ 
\max_{1\leq i \leq n} (p_i + OPT(n-i)) & \quad \text{otherwise}
\end{cases}
$$

## Matrix Chain Multiplication

Sea $m[i,j]$ la mínima cantidad de productos escalares para computar $A_{i:j}$
Definimos $m[i,j]$ recursivamente como sigue:

$$
m[i,j] = 
\begin{cases}
0 \quad & i = j\\
\min_{i\leq k < j} m[i, k] + m[k+1, j] + p[i-1]p[k]p[j] \quad & i < j
\end{cases}

$$

## Longest increasing subsequence


$$
OPT(n) =
\max_{j < i} {OPT(j) : A[j] < A[i]}


$$

