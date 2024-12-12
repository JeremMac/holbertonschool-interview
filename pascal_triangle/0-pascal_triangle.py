def pascal_triangle(n):
    if n <= 0:
        return []

    triangle = []
    for i in range(n):
        row = [1] * (i + 1)  # Crée une ligne avec des 1
        if i > 1:  # À partir de la troisième ligne
            for j in range(1, i):
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j]
                # Somme des deuxéléments au-dessus
        triangle.append(row)

    return triangle
