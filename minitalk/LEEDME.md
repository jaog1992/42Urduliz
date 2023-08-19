<h1 align="center">
	📖 minitalk
</h1>

<p align="center">
	<b><i>Comunica dos procesos usando señales</i></b><br>

# Instrucciones Generales

## 💡 Parte obligatoria

Este proyecto busca que el programador se familiarice con el uso de señales y su funcionamiento. Para ello limita el uso de señales a SIGUSR1 y SIGUSR2.

Estas señales son configurables por el usuario y han de ser gestionadas a con los comandos signal, sigaction...

TIP: Repasa los operadores de bit para entender el código

| Operador | Explicacion |
| --- | --- |
| '|' |
| & | |


	Signum es el valor numérico de la señal
	*info da información sobre qué proceso la envía, el código de señal, hora...
	Da información del contexto de la señal como registros de CPU, pila etc...
	no lo usaremos.
	Constantes de stdlib: EXIT_SUCCESS=1 EXIT_FAILURE=0

# 📋 BIBLIOGRAFIA

* [Estructura sigaction](https://www.qnx.com/developers/docs/6.5.0SP1.update/com.qnx.doc.neutrino_lib_ref/s/sigaction_struct.html)
