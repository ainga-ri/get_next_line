void ft_freecopy(static char *new_guardado, char *concat)
{
	if (ft_strlen(concat) > 0)
		free(concat);
	concat = ft_copy(new_guardado);
	free(new_guardado);
	new_guardado = "";
}
