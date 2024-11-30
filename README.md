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
* 1 Zumbador
* Una impresora 3D para poder imprimir TODOS los diseños
* Silicona Caliente
* Cartón
* Esponjas
* Madera
* Alambres
* Cinta blanca

### 1.1. Diseños
Todos estos diseños fueron construidos en FreeCad, y son las piezas que componen el Cscarrabias-9000:

#### Caja
##### [Cuerpo](https://github.com/evafc003/Mecatronica-Proyectos/blob/main/Dise%C3%B1os_definitivos_imprimibles/Caja/Caja.stl)
##### [Tapa](https://github.com/evafc003/Mecatronica-Proyectos/blob/main/Dise%C3%B1os_definitivos_imprimibles/Caja/Tapa.stl)
#### Cascarrabias
##### [Cuerpo](https://github.com/evafc003/Mecatronica-Proyectos/blob/main/Dise%C3%B1os_definitivos_imprimibles/Cascarrabias/Cascarrabias_con_mecanismo.stl)
##### [Soporte](https://github.com/evafc003/Mecatronica-Proyectos/blob/main/Dise%C3%B1os_definitivos_imprimibles/Cascarrabias/soporte.stl)
##### [Brazo](https://github.com/evafc003/Mecatronica-Proyectos/blob/main/Multimedia/Vídeos/brazo_cascarrabias.mp4)

## 2. Funcionamiento e inspiración del proyecto
### 2.1. Inspiración
Como tomé la decisión de hacer este peoyecto en solitario, buscaba un proyecto **sencillo y divertido**.

Pensando en qué me podría basar, recordé [este vídeo de youtube](https://youtu.be/wlslwdB9Z4g?feature=shared).

Entonces, decidí replicarlo y mejorarlo a mi manera.

#### 2.1.2. Dificultades
Sin embargo, a la hora del desarrollo me topé con varias dificultades:

La principal difilcutad que tuve a la hora del desarrollo del proyecto fue que tengo una **visión espacial** bastante pobre, cosa que me dificultó mucho el proceso para hacer los diseños. De hecho, el diseño de la caja que muestro no funciona, y me tocó comprar unas visagras.

Por otro lado, ajustar el piñón y los mecanismos en general a mi caja también se me hizo complicado, ya que todo este ajuste se hizo desde FreeCad.

También, a la hora del montaje, también se me complicó un poco el hecho de colocar los motores, ya que tenía que visualizar el giro que iiban a hacer para que toodo fuese correctamente, pero, además de esto, tuve el problema de que el motor del brazo no era lo suficientemente fuerte como para ccionar el botón y tuve que cambiar radicalmente el enfoque del proyecto, ya que la función que le daba "gracia" a mi Cascarrabias-9000 era precisamente que él mismo accionase el botón.

Para solucionar eso, el enfoque que le di fue hacer que no lo pulsara, si no que te obligase a tí a hacerlo, siendo muy, muy, pero que muy insistente. Cosa que funcionó bastante bien y le dio un toque más original al proyecto, ya que no es replicar el original y añadirle cosas, sino darle otra perspectiva.

También un problema relacionado con los motores fue que no tenían fuerza tampoco para levantar la caja sin sobrecalentar el motor, cosa que hacia que la placa se sobrecalentase y reiniciase, por lo que tuve que cambiar esta pieza por una plancha de cartón a la hora de terminar el proyecto.

### 2.2. Funcionamiento

#### 2.2.1. Documentación
Como "funcionamiento personal", es decir, para ver cómo me he organizado y lo que he hecho en profundidad, existe la [wiki del proyecto](https://github.com/evafc003/Mecatronica-Proyectos/wiki).

#### 2.2.2. Funcionamiento del robot
El funcionamiento del Cascarrabias-9000 es muy sencillo, ya que, simplemente consta de un botón de que hay que accionar, y, cuando se acciona, encendemos un led que hace de "despertador" que hace enfurecer a cascarrabias y lo hace salir para obligarnos a volver a accionar el botón, para así apagar la luz y permitir que Cascarrabias siga durmiendo. Para lograr este comportamiento, primero se ha seguido este circuito eléctrico para el hardware:

<p align="center">
<img src= "https://github.com/evafc003/Mecatronica-Proyectos/blob/main/Multimedia/Fotos/circuito_final.png", width=1080>
</p>

Lo que en la vida real tiene este aspecto:

<p align="center">
<img src= "https://github.com/evafc003/Mecatronica-Proyectos/blob/main/Multimedia/Fotos/montaje_3.jpeg", width=1080>
</p>

Y, para el software, lo que se ha implementado ha sido que, dependiendo del tiempo que tardes en presionar de nuevo el botón, Cascarrabias se va enfureciendo y cada vez es más "agresivo", para así obligarnos a presionar el botón.

Para conseguir esto, se usan temporizadores que van llamando a funciones cuando toca, en un "plazo" de X, cuando pasa este plazo, el ciclo se repite y empezamos desde el principio, dejo a continuación lo que pasa y en qué momento:
##### Segundo 10: Siendo Amables

La primera vez que despertamos a Cascarrabias, éste intenta ser amable y pedir educadamente que presionemos el botón. Para ello, hará movimientos y sonidos suaves, para que captes su mensaje.

##### Segundo 20: Siendo menos amables

Si no captamos el mensaje a la primera, Cascarrabias irá perdiendo la paciencia, de modo que los movimientos y sonidos se alterarán un poco, pero aún no será desagradable.

##### Segundo 32: Recordando nuestra existencia

La segunda vez que no sepas que lo que hay que hacer es presionar el botón, Cascarrabias dudará de tu inteligencia y/o atención y te indicará de nuevo que pulses el botón, haciendo un ruido de duda.

##### Segundo 40: Comenzando a enfadarnos

Si Cascarrabias ve que no le prestas atención, comenzará a enfadarse y a volver sus movimientos más bruscos y sus sonidos más estridentes, de modo que se note que se ha enfadado.

##### Segundo 55: Perdiendo la cordura

Este comportamiento será algo más agresivo que el anterior.

##### Segundo 80: Volviéndonos locos

Si llegas a este punto, no solo Cascarrabias habrá perdido los modales, sino que tú también lo harás si no pulsas el botón rápidamente.

A parte de estos comportamientos, si acercamos demasiado la mano o soplamos en el sensor de humedad, CAscarrabias se asustará, a no ser que esté demasiado enfadado.
## 3. Demostración del funcionamiento

Una vez entendido lo que es y cómo funciona mi proyecto, ha llegado la hora de enseñarlo funcionando.

https://github.com/user-attachments/assets/525335d7-f0b2-42a6-8477-e751c7b411d2

## 4. Conclusión y posibles usos
Como conclusión puedo aportar que este proyecto de robot educativo me ha enseñado a trabajar más con la **visión espacial** y el diseño 3D, ya que la programación, al ser una cosa muy usada en mi día a día, no me aportó mucho, todo eran cosas que ya había visto o muy parecidas a cosas hechas en el pasado.

También como conclusión creo que ha sido un proyecto muy chulo que me ha divertido bastante, ya que partir del cero absoluto y acabr teniendo mi propio CAscarrabias-9000 ha sido muy satisfactorio e inspirador.

En cuanto a los usos de mi robot, la verdad que no son muchos, pero se me ocurren estos 2:
* Juguete
* Enseñar
