# Proyecto Final

## Numpad Custom

En este proyecto nos planteamos diseñar un teclado numérico desde cero, tanto la estructura del teclado como la electrónica.

### Diseño y ensamblado de la estructura

Sabiendo que en la UGR tenemos acceso a impresoras 3D y cortadoras láser decidimos hacer una estructura de capas de metacrilato. Dichas capas irán fijadas mediante tornillos y tuercas.

Para el diseño de estas piezas usamos íntegramente FreeCAD.


![Alt text](./img/2021-04-18-122013.jpg?raw=true "Corte en Bibliomaker")
![Alt text](./img/2021-04-18-122111.jpg?raw=true "Corte en Bibliomaker")

Una vez diseñadas las piezas fuimos a cortarlas al Bibliomaker en la biblioteca de la facultad de ciencias.

![Alt text](./img/photo_2021-04-08_11-33-59.jpg?raw=true "Corte en Bibliomaker")

Mis agradecimientos al equipo del Bibliomaker (en especial a Teo), que nos ayudó y enseñó a usar la cortadora láser.

Este fue el resultado del corte.

![Alt text](./img/photo_2021-04-08_11-33-46.jpg?raw=true "Corte terminado")

Estas piezas tienen un plástico protector, por tanto el siguiente paso fue limar los defectos y quitar dicho plástico protector.

![Alt text](./img/photo_2021-03-15_12-22-49.jpg?raw=true "Corte procesado")
![Alt text](./img/photo_2021-04-08_11-35-46.jpg?raw=true "Corte procesado")

Ahora vamos a ensamblar el cuerpo del numpad

![Alt text](./img/photo_2021-03-15_17-19-52.jpg?raw=true "Ensamblaje")
![Alt text](./img/photo_2021-04-08_11-35-42.jpg?raw=true "Ensamblaje")
![Alt text](./img/photo_2021-04-08_11-35-28.jpg?raw=true "Ensamblaje")
![Alt text](./img/photo_2021-04-08_11-35-32.jpg?raw=true "Ensamblaje")



Hemos usado interruptores Gateron Brown y unas teclas con estampados

### Electrónica

Para la electrónica hemos hecho uso de cables, 17 diodos (uno por cada tecla) y un microcontrolador Teensy 2.0 (https://www.pjrc.com/store/teensy.html)

Hay que hacer una matriz con los interruptores haciendo que en las filas los interruptores estén conectados a estas mediante un diodo.

![Alt text](./img/photo_2021-03-15_22-38-00.jpg?raw=true "Corte procesado")
![Alt text](./img/photo_2021-03-19_16-55-41.jpg?raw=true "Corte procesado")

Una vez hecho estoy hay que hacer que cada fila y cada columna esté conectada a un pin I/O del microcontrolador.

![Alt text](./img/photo_2021-03-19_17-09-47.jpg?raw=true "Corte procesado")

Finalmente se comprueba que todas las soldaduras están hechas de la forma adecuada.

![Alt text](./img/photo_2021-04-15_15-41-00.jpg?raw=true "Corte procesado")

### Firmware

Para el firmware hemos utilizado QMK (https://github.com/qmk/qmk_firmware), este firmware permite configurar teclados que usen estos microcontroladores https://beta.docs.qmk.fm/developing-qmk/c-development/compatible_microcontrollers .

Siguiendo la guía que tienen en la documentación oficial (https://beta.docs.qmk.fm/tutorial/newbs) es relativamente facil de configurar el entorno de desarrollo del firmware.

Nuestro teclado le pusimos de nombre PDIH por eso tenemos una carpeta con ese nombre en este directorio.

Estos son los datos que identifican al numpad.

```c
/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    LaguilargXiqqdd99
#define PRODUCT         PDIH-numpad
#define DESCRIPTION     PDIH-numpad
```
Aquí definimos cuales son las filas y las columnas, así como a que pines asociamos cada fila y cada columna con el microcontrolador. También tenemos que indicar que orientación tienen los diodos.

```c
/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 4

/* key matrix pins */
#define MATRIX_ROW_PINS { B0, F1, F4, F6, C7 }
#define MATRIX_COL_PINS { F0, D4, F7, F5 }
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL
```

