
# Dynamic Programming cses problemset


## Removing Digits

Sea $n=\overline{d_1d_2...d_j}$ un número con $j$ dígitos.

Sea $OPT(n)$ la cantidad mínima de pasos para hacer 0 el número $n$ sustrayendo uno de sus dígitos. Definimos $OPT(n)$ recursivamente como sigue:
$$
OPT(n)=
\begin{cases}
1 & \quad \text{when $n$ has only one digit}\\ 
\min_{1\leq i \leq j} \{OPT(n - d_i)\} + 1 & \quad \text{otherwise}
\end{cases}
$$

Subestructura óptima:


## Grid paths

Sea $M[0…n-1,0…n-1]$  una cuadrícula $n\times n$.

Sea $dp[i,j]$  el número de caminos posibles para llegar desde $M[i,j]$ a $M[n-1,n-1]$ con $0\leq i\leq j \leq n$. Definimos $dp[i,j]$ recursivamente como sigue:

$$
dp[i,j]=
\begin{cases}
0 & \quad \text{when $i=n ∨ j=n ∨ M[i,j]="*"$}\\ 
1 & \quad \text{when $i=n-1 ∧j=n-1$}\\
dp[i + 1,j] + dp[i + 1,j] & \quad \text{otherwise}
\end{cases}
$$