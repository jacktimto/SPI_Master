set(srcs "pretty_effect.c"
         "main.c"
         "decode_image.c"
         "./app/Display_EPD_W21.c"
         "./app/Display_EPD_W21_spi.c"
    )

set(dirs "."
         "./app"
    )

idf_component_register(SRCS ${srcs}
                    INCLUDE_DIRS ${dirs}
                    EMBED_FILES image.jpg)
