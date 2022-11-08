# Aplicación para programa de lealtad

## Contexto

Un programa de lealtad o programa de fidelización es una estrategia para aumentar las ventan de un negocio. Los participantes del programa ganan y acumulan puntos para gastarlos en su próxima compra o para tener ofertas personalizadas

Existen diversas ventajas en tener un programa de lealtad como estimular a los clientes a comprar más, ofrecer incentivos progresivos, mantener contentos a tus compradores, es algo que no requiere mucho esfuerzo y que permite crecer tu negocio.

Hay diversos sistemas que se pueden aplicar para un programa de lealtad, como el sistema de puntos, el cual en básicamente funciona así: el cliente hace la compra y obtiene puntos, la cantidad depende del monto del pedido. Normalmente, los puntos tienen fecha de caducidad (por ejemplo: de 5 días a 3 semanas) para estimular a los clientes a comprar para no perderlos; o un sistema de niveles en el cual los miembros más recientes reciben bonificaciones pequeñas, ya sea cantidad de puntos, monto de cashback o un descuento personalizado. Al aumentar el importe total de compras, el cliente pasa a un nivel más alto con el respectivo aumento de descuentos, cantidad de puntos, etc.

## Nuestro cliente

El restaurante BrunchyTime es un restaurante que ofrece comida TexMex, tiene un par de años en el mercado y durante este tiempo ha tenido muy buen recibimiento con sus clientes, muchos de ellos acuden con cierta frecuencia al restaurante y ordenan comida a domicilio.

### Sistema actual

Sabiendo esto, el dueño de BrunchyTime, mejor conocido como "Don Brunch", ha implementado un sistema de lealtad. Su sistema consta de una serie de tarjetas que cuentan con 10 espacios para 10 sellos; cada que un cliente asiste a una de las sucursales, el o la cajera le pregunta al cliente si ya cuenta con su BrunchyCard y le ofrece una en caso de no contar con una.
Después de cada compra en cualquier sucursal, la cajera sella la BrunchyCard del cliente sí la compra fue igual a mayor a 150 MXN.
Cuando el cliente llena la tarjeta de sellos, es acreedor a un platillo gratis y se le otorga una nueva BrunchyCard.

Aunque ha dado buenos resultados este sistema, Don Brunch ha notado algunas desventajas, por ejemplo:
* Al ser una tarjeta física, hay ocasiones en las que el cliente pierde la tarjeta y la única forma de validar los sellos que tenía la BrunchyCard es pedirle al cliente alguna foto reciente de la tarjeta.
* La solución anterior es una solución a medias, ya que hay que confiar en que el cliente este mostrando una foto que el mismo haya tomado y no sea una foto de una BrunchyCard mas llena de sellos.
* Los sellos solo se puede poner de forma física, es decir, si el cliente pide comida a domicilio no hay forma de hacerle sellarle la BrunchyCard.
* No importa la cantidad de consumo, el sello aplica si consumes $150 o $800 pesos, no hay una recompensa mayor por mayor consumo.
* La BrunchyCard no tiene vigencia: no hay un incentivo para consumir mas o perder los sellos porque no hay una caducidad como tal.
* No hay un registro de la información de los sellos, es decir, solo existe un sello como prueba de una compra en alguna sucursal, pero no se tiene registro de cual fue el monto de la compra de algun sello, cuando se realizo, en que sucursal se hizo la compra.
* No hay un registro de cuantas tarjetas ha canjeado un cliente.
* Solo hay una promoción o beneficio que se puede obtener al canjear la BrunchyCard una vez llenado los sellos.

### Solicitud de nuevo sistema

Gracias al networking que hemos hecho, tuvimos la oportunidad de conocer y tener una junta con el Don Brunch en la cual nos presentamos, hablamos de nuestra experiencia como ingenieros de software, y nos platicó acerca de su negocio y su sistema actual. 
Después de una larga charla en la que le planteamos los beneficios de llevar su sistema de lealtad a una aplicación, nos contrato para desarrollar una aplicación que le ayude a adiminstrar su programa de lealtad actual ademas de incorporar mejoras en el mismo.
Sabemos que los negocios cambian constantemente por diversos factores, y eso mismo le hicimos saber eso a Don Brunch, que nuestra aplicación le permitirá tener un mayor control sobre su proceso actual y la robustez de nuestro sistema permitirá adicionar nuevas funcionalidades en el futuro, pero primero necesitamos partir de unos requerimientos base los cuales necesitamos definirlos junto con Don Brunch para tener claras las expectativas de la aplicación.

Después de dos semanas de entablar comunicación con el dueño, en la cual estuvimos poniendonos de acuerdo en cuales son las necesidades que se necesitan cubrir por la aplicación, de resolución de algunas dudas que tuvimos respecto al modelo y reglas de su negocio así como proponer interfaces de usuario, llegamos a una serie de requisitos para esta primera etapa. Además, Don Brunch ya tenía nombre para la aplicación: la BrunchyApp.

# BrunchyApp

Junto con Don Brunch, establecimos la serie de funcionalidades que debe de tener esta primera etapa, pero antes de definirlas necesitamos saber el contexto de los actores que intervienen en el sistema actual de BrunchyTime.


## Actores o entidades


| Actor      | Descripción                                                                                               |
| ---------- | --------------------------------------------------------------------------------------------------------- |
| Usuario    | Un usuario es cualquier empleado de BrunchyTime que puede hacer uso de esta aplicación                     |
| Cliente    | Un cliente es una persona que asiste o llama al restaurante para ordenar comida                           |
| Sucursal   | Representa un restaurante físico                                                                          |
| BrunchyCard | Representa una BrunchyCard física                                                                          |
| BrunchySello | Representa un sello |
| Promocion  | Representa una promoción que es un beneficio que se otorga al cliente luego de cierta cantidad de compras |

## Casos de uso

Las funcionalidades o casos de uso principales que debe tener la BrunchyApp son:

*_Nota:_*  un wizard un formulario o pantalla que le presenta al usuario una serie de pasos pequeños para capturar y/o mostrar información.

___

### [_Cliente sin BrunchyCard Digital con BrunchyCard fisica (cliente existente)_](#nuevo_cliente_con_bc_fisica):

1- El cliente se acerca a la caja a pagar y muestra su BrunchyCard física.

2- El cajero le comenta al cliente que ahora estan cambiando a una BrunchCard digital y que la BrunchyCard física ya no se estará manejando, todo esto mientras el cajero entra al apartado del _wizard_ de nueva BrunchyCard.

3 - El cajero le pregunta al cliente su nombre, numero de teléfono celular y un correo electrónico opcional, los cuales captura en el paso de alta de cliente en el _wizard_. [Ver ejemplo](https://csshint.com/bootstrap-wizard/)

4- El cajero selecciona la opcion de cliente existente en el paso de _Tipo de cliente_ en el _wizard_.

5- El cajero captura la cantidad de sellos de la BrunchyCard física en el paso de BrunchySellos registrados del _wizard_. 

6- En el paso de _Confirmación de datos_ del _wizard_ el cajero confirma los datos ingresados con el cliente.

7- El cajero guarda la información, el _wizard_ muestra el número de cliente que se ha generado para el cliente y se lo notifica al cliente.

___

### _Cliente sin BrunchyCard Digital y sin BrunchyCard fisica (cliente nuevo)_:

1- El cliente se acerca a la caja a pagar.

2- El cajero le pregunta al cliente si quiere obtener su BrunchyCard digital, a lo que el cliente constesta que si.

3- El cajero entra al _wizard_ de nueva BrunchyCard.

4 - El cajero le pregunta al cliente su nombre, numero de teléfono celular y un correo electrónico opcional, los cuales captura en el paso de alta de cliente en el _wizard_. [Ver ejemplo](https://csshint.com/bootstrap-wizard/)

5- El cajero selecciona la opcion de cliente nuevo en el paso de _Tipo de cliente_ en el _wizard_.

6- En el paso de _Confirmación de datos_ del _wizard_ el cajero confirma los datos ingresados con el cliente.

7- El cajero guarda la información, el _wizard_ muestra el número de cliente que se ha generado para el cliente y se lo notifica al cliente.

8- El cajero finaliza el wizard.
___

### _Cliente paga y solicita un BrunchySello_:

1- El cajero entra al apartado del wizard de nuevo BrunchySello.

2- El cajero le pide el número de cliente o número de celular y lo captura en el paso de _Ingrese cliente_ del wizard de nuevo BrunchySello.
 - Si el cliente no existe entonces se procede a darlo de alta.
 - Si el cliente existe entonces el cajero valida el nombre que aparece en el wizard con el cliente y avanza al siguiente paso, el paso de "Registro de compra".

3- En el paso de Registro de compra, el cajero revisa ingresa el monto de compra, guarda la información y avanza al siguiente paso.

4- En el paso de _Confirmación de compra_ del wizard el cajero confirma los datos ingresados con el cliente.

5-El cajero avanza al paso final del wizard, que es el de "BrunchySello generado" donde el sistema genera un nuevo BruncySello.

6-En el paso del "BrunchySello generado" el cajero le confirma que ya esta cuenta con un nuevo sello.

7- El cajero finaliza el wizard.

___

### _Cliente pide comida a domicilio_

1- Al recibir la notificación de pago del pedido, el cajero revisa el número de teléfono del cliente.

2- El cajero entra al apartado del wizard de nuevo BrunchySello.

3- El cajero le pide el número de cliente o número de celular y lo captura en el paso de _Ingrese cliente_ del wizard de nuevo BrunchySello.
 - Si el cliente no existe entonces se procede a darlo de alta.
 - Si el cliente existe entonces el cajero valida el nombre que aparece en el wizard con el cliente y avanza al siguiente paso, el paso de "Registro de compra".

4- En el paso de Registro de compra, el cajero revisa ingresa el monto de compra, guarda la información y avanza al siguiente paso.

5- En el paso de _Confirmación de compra_ del wizard, el cajero confirma los datos.

6-El cajero avanza al paso final del wizard, que es el de "BrunchySello generado" donde el sistema genera un nuevo BruncySello.

7-En el paso del "BrunchySello generado" el cajero toma nota del BrunchSello generado y se lo notifica al cliente a traves del medio por donde creado el pedido.

8- El cajero finaliza el wizard.

___

### _Cliente ha llenado su BrunchiCard _

1- En el paso del "BrunchySello generado", si el cliente ha alcanzado la cantidad de sellos de su BrunchyCard, el wizard le notificará al cajero que el cliente ya puede redimir su BrunchyCard mediante un mensaje en la pantalla.

2- El cajero le notifica al cliente que en su siguiente visita puede redimir su BrunchyCard.

3- El cajero finaliza el wizard.

____

## CASOS PENDIENTES

### _Cliente con BrunchyCard llena no quiere redimir su BrunchyCard pero quiere que le cuente la compra_
### _Cliente pierde el telefono o quiere cambiar el que tiene registrado_
### _Cliente redime su BrunchyCard y el sistema genera otra nueva_
### _Administrador genera reporte de brunchycards del sistema_
### ...Recabar mas información


## Ideas
### _Cambiar los Brunchysellos por BrunchyPuntos_
Los brunchypuntos van a permitir que en base al monto de compra se puedan asignar diversa cantidad de puntos y no solo un sello por compra ([Concepto similar a mercado puntos](https://www.mercadolibre.com.mx/l/mercado-puntos-beneficios))
### _Definir promociones por cantidad de brynchypuntos_
El administrador puede definir una promocion por _N_ cantidad de puntos, por decir:
- Un jugo por 20 puntos
- Unos chilaquiles por 50 puntos
- Un jugo con chilaquiles por 65 puntos
De esta manera se le da la flexibilidad al cliente de elegir cuando redimir su BrunchyCard
### _El administrador puede crear distintos tipos de promociones:_
El administrador tendrá la oportunidad de definir promociones como:
 - promociones fijas
 - promos limitadas
 - promocion por consumo mayor a 500
 - promocion de TopFAN
en base a diversos parametros y datos registrados en el sistema
### _El administrador define tipos de cliente_
En base al historial de consumo del cliente, el administrador puede brindarle mas beneficios o promociones diferentes para premiar su lealtad.
### _Generar una app para el cliente_ 
A traves de un app/un servicio de notificaciones/un bot, el cliente podrá consultar sus brunchysellos, brunchypuntos, promociones, su tipo de cliente



# NOTAS EXTRA

### Requisitos del modulo de usuarios

La aplicación debe de contar con 2 tipos de usuarios:
- Administradores: Cada sucursal cuenta con un administrador, y todos los administradores tendrán acceso a todas las funciones del sistema.
- Cajeros: cada sucursal cuenta con al menos un cajero, el cual es el encargado de registrar los sellos en la BrunchyCard. Tiene acceso limitado a las funciones de la aplicación.




