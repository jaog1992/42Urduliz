<h1 align="center">
	📖 minitalk
</h1>

<p align="center">
	<b><i>Comunica dos procesos usando señales</i></b><br>

# Instrucciones Generales

## 💡 Parte obligatoria

Este proyecto busca que el programador se familiarice con el uso y manipulación de las señales en procesos. 
Para ello se ha, de comunicar 2 procesos, cliente y servidor, usando las señales SIGUSR1 y SIGUSR2.

Estas señales son configurables por el usuario y han de ser gestionadas con los comandos 
* [signal](https://man7.org/linux/man-pages/man7/signal.7.html)
* [sigaddset](https://man7.org/linux/man-pages/man3/sigaddset.3p.html)
* [sigemptyset](https://man7.org/linux/man-pages/man3/sigemptyset.3p.html)
* [sigaction](https://man7.org/linux/man-pages/man2/sigaction.2.html)
* [kill](https://man7.org/linux/man-pages/man2/kill.2.html)
* [getpid](https://man7.org/linux/man-pages/man2/getpid.2.html)
* [pause](https://man7.org/linux/man-pages/man2/pause.2.html)
* [sleep](https://man7.org/linux/man-pages/man3/sleep.3.html)
* [usleep](https://man7.org/linux/man-pages/man3/usleep.3.html)
* [exit](https://man7.org/linux/man-pages/man3/exit.3.html)

TIP: Repasa los [operadores de bit](https://learn.microsoft.com/en-us/cpp/c-language/c-bitwise-operators?view=msvc-170) para entender el código

Evidencias a tener en cuenta:
- Si solo usas ```signal``` corres el riesgo de que pierdas señales enviadas, ya que no se serializa/encola su envío y cualquier señal de segundo plano puede hacer que se pierda la señal.
  Tendrás que configurar un ack para chequear que ha llegado y un método de comprobación de integridad del mensajes, como un [bit de paridad](https://es.wikipedia.org/wiki/Bit_de_paridad)
- Cada proceso tiene asignadas su zonas de memoria independientes. No pueden compartirlas.

Resultado de la parte mandatory:

![minitalk mandatory](./Img/minitalk.gif "minitalk mandatory")

## Parte bonus

Para la parte bonus se pide que el servidor responda al cliente y que sepa interpretar mensajes unicode.

En esta implementación el servidor responde con un SIGUSR2 en caso de recibirlo correctamente y el cliente representa un ✅ cada vez que recibe este ack.

![minitalk bonus](./Img/minitalk_bonus.gif "minitalk bonus")

# 📋 BIBLIOGRAFIA

* [Estructura sigaction (tambien sale en el man)](https://www.qnx.com/developers/docs/6.5.0SP1.update/com.qnx.doc.neutrino_lib_ref/s/sigaction_struct.html)
