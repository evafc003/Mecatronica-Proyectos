# Mecatronica-Proyectos
Este repositorio es el que almacenará el desarrollo del proyecto para la asignatura Mecatrónica, del grado en ingeniería robótica software

Este fichero README.md se utilizará para presentar el proyecto en clase. Si quieres más información sin tener que leerla, puedes diretamente visitar [este enlace](https://github.com/evafc003/Mecatronica-Proyectos/wiki).

# Presentación del proyecto. Cascarrabias-9000

## 1. Materiales
* Una placa Arduino (en mi caso mega)
* 2 servomotores
* 1 Switch de palanca
* 1 LED (da igual el color)
* 1 Sensor de ultrasonidos
* 1 Sensor de humedad DHT11
* Una impresora 3D para poder imprimir TODOS los diseños
* Silicona Caliente
* Cartón
* Esponjas
* Madera
* Alambres

### 1.1. Diseños
Todos estos diseños fueron construidos en FreeCad, y son las piezas que componen el Cscarrabias-9000:

#### Caja
##### [Cuerpo](https://github.com/evafc003/Mecatronica-Proyectos/blob/main/Dise%C3%B1os_definitivos_imprimibles/Caja/Caja.stl)
##### [Tapa](https://github.com/evafc003/Mecatronica-Proyectos/blob/main/Dise%C3%B1os_definitivos_imprimibles/Caja/Tapa.stl)
#### Cascarrabias
##### [Cuerpo](https://github.com/evafc003/Mecatronica-Proyectos/blob/main/Dise%C3%B1os_definitivos_imprimibles/Cascarrabias/Cascarrabias_con_mecanismo.stl)
##### [Brazo](https://github.com/evafc003/Mecatronica-Proyectos/blob/main/Multimedia/Vídeos/brazo_cascarrabias.mp4)

## 2. Funcionamiento e inspiración del proyecto
### 2.1. Inspiración
Como tomé la decisión de hacer este peoyecto en solitario, buscaba un proyecto **sencillo y divertido**.

Pensando en qué me podría basar, recordé [este vídeo de youtube](https://youtu.be/wlslwdB9Z4g?feature=shared).

Entonces, decidí replicarlo y mejorarlo a mi manera.

### 2.2. Funcionamiento

#### 2.2.1. Documentación
Como "funcionamiento personal", es decir, para ver cómo me he organizado y lo que he hecho en profundidad, existe la [wiki del proyecto](https://github.com/evafc003/Mecatronica-Proyectos/wiki).

#### 2.2.2. Funcionamiento del robot
El funcionamiento del Cascarrabias- es muy sencillo, ya que, simplemente consta de un botón de que hay que accionar, y, cuando se acciona, encendemos un led que hace de "despertador", cosa que hace enfurecer a cascarrabias y lo hace salir para volver a accionar el botón, apagar la luz y seguir durmiendo. Este comportameinto se repite en bucle, sin embargo, tiene 6 comportamientos diferentes:

##### COMPORTAMIENTO 1

Éste es el más sencillo de todos, el cual simplemente hace que cascarrabias salga, presione el botón  se esconda de nuevo.

VIDEO

##### COMPORTAMIENTO 2

Éste comportamiento es algo más complejo que el anterior, ya que Cascarrabias sale, pero, en vez de apagar el botón directamente, hace unos movimientos que nos indican que dejemos el botón en paz antes de esconderse.

VIDEO

##### COMPORTAMIENTO 3

Para este comportamiento, lo que hace Cascarrabias sale, pero, una vez harto de que le despertemos por tercera vez, éste deja la mano encima del botón para que no podamos accionarlo, a no ser que acerquemos la mano al sensor de ultrasonidos para asustarle.

VIDEO

##### COMPORTAMIENTO 4

Este cuarto comportamiento es igual que el anterior, sin embargo, esta vez hay que soplar en el sensor de humedad para que Cascarrabias se esconda.

VIDEO

##### COMPORTAMIENTO 5

Para el comportamiento número 5, lo que hace cascarrabias es levantarse, accionar el botón e irse, sin embargo, cuando acercamos la mano par avolver accionar el botón, vuelve a salir sin darnos tiempo a hacerlo, a no ser que le dejemos tranquilo 10 segundos.

VIDEO

##### COMPORTAMIENTO 6

En el comportamiento número 6 podemos ver la desesperación de cascarrabias, ya que, una vez que accionamos el botón, la tapa de caja "vibrará" en señal de que cascarrabias está harto de nosotros antes de accionar de nuevo el botón, sin embargo, una vez lo acciona, tendremos que soplarle 3 veces para que se rinda y se vuelva a esconder.

VIDEO

## 3. Dificultades
La principal difilcutad que tuve a la hora del desarrollo del proyecto fue que tengo una **visión espacial** bastante pobre.

Esto me dificultó mucho el proceso para hacer los diseños. 

De hecho, el diseño de la caja que muestro no funciona, y me tocó comprar unas visagras.

Por otro lado, ajustar el piñón y los mecanismos en general a mi caja también se me hizo complicado, ya que todo este ajuste se hizo desde FreeCad.

Y, por último, a la hora del montaje, también se me complicó un poco el hecho de colocar los motores, ya que tenía que visualizar el giro que iiban a hacer para que toodo fuese correctamente.

Pero, a pesar de todo esto, el proyecto consiguió salir adelante satisfactoriamente.

## 4. Conclusión y posibles usos
Como conclusión puedo aportar que este proyecto de robot educativo me ha enseñado a trabajar más con la **visión espacial** y el diseño 3D, ya que la programación, al ser una cosa muy usada en mi día a día, no me aportó mucho, todo eran cosas que ya había visto o muy parecidas a cosas hechas en el pasado.

En cuanto a los usos de mi robot, la verdad que no son muchos, pero se me ocurren estos 2:
* Juguete
* Enseñar
