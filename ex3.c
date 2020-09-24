# define  CORBRANCO (makecol ( 255 , 255 , 255 ))
# define  CORPRETO  1
# define  CORCINZA (makecol ( 160 , 160 , 160 ))
# define  CORAZUL (makecol ( 0 , 0 , 255 ))
# define  CORVERDE (makecol ( 0 , 255 , 0 ))
# define  CORAMARELO (makecol ( 255 , 255 , 100 ))
# define  CORVERMELHO (makecol ( 255 , 0 , 0 ))

# define  IMAGENAME  " teste.bmp "  /* nome do arquivo de imagem */

# include  <stdio.h>
# include  <allegro.h>

int  main (void)
{
  BITMAP * buff;
  PALETTE pal;

  if ( install_allegro (SYSTEM_NONE, & errno, atexit )! = 0 )
    sair (EXIT_FAILURE);

  set_color_depth ( 16 );
  get_palette (pal);

  // Crie um buffer para uma animação suave.
  buff = criar mapa de bits ( 320 , 240 );
  if (buff == NULL )
  {
    printf ( " Não foi possível criar o buffer! \ n " );
    sair (EXIT_FAILURE);
  }

  círculo (amarelo, 160 , 120 , 100 , CORAMARELO);
  textprintf_ex (buff, font, 50 , 50 , CORVERDE, CORPRETO, " Teste do circulo. " );

  save_bitmap (IMAGENAME, buff, pal);
  destroy_bitmap (buff);
  allegro_exit ();

  printf ( " Imagem % s salva com sucesso! \ n " , IMAGENAME);

  return EXIT_SUCCESS;
}
END_OF_MAIN ()
