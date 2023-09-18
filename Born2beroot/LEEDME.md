<h1 align="center">
	📖 Born2beroot
</h1>

<p align="center">
	<b><i>Notas personales para una corrección ágil</i></b><br>

# General Instructions

# Mandatory part
Para comprobar el hostname se puede hacer con el comando ```hostnamectl```, y puede ser cambiado con ```hostnamectl set-hostname```.

Tambien puede hacerse modificando el archivo ***/etc/hostname*** como root y luego resetear el servidor:

```sudo nano /etc/hostname```

# Que shell de Unix estoy usando?

Podemos usar el comando **ps** con la opción **-p {pid}**. Este comando selecciona los procesos cuyo ID aparece en el pid introducido.

```ps -p $$```

 el símbolo del **$** devuelve el PID (process identification number) del proceso actual, y como en este caso es la s and the current process is your shell. So running a ps on that number displays a process status listing of your shell. In that listing, you will find the name of your shell (look for CMD column).

# Project Overview
## Qué es una máquina virtual

Es un software basado en Hipervisor que permite que puedas ejecutar un ordenador/servidor, sin dependencias físicas, con un Sistema operativo, Kernel, recursos y configuraciónes independientes al host. Permite ser copiado de un ordenador a otro, por lo que es muy útil de cara a compartir un entorno local común en equipos de trabajo.

## Por qué has escogido Debian

Porque quería aprender a configurar una distribución de GNU/Linux y esta se caracteriza por su filosofía de software libre y robustez (Ubuntu se basa en Debian). Esto hace factible que vuelva a configurar MV-s de esta distribución a futuro.

## Principales diferencias entre Centos y Debian

CentOS (Community Enterprise Operating System) es un sistema operativo de código abierto basado en en RHEL (Red Hat Enterprise Linux; Tienen compatibilidad binaria). Aunque se desarrolla en colaboración con una comunidad de voluntarios es la versión empresarial de RHEL, lo cual supone un modelo de versionado conservador = + soporte y estabilidad. Usan YUM y DNF com gestores de paquetes.

Debian es una distribución de Linux independiente que se desarrolla y mantiene por una comunidad de usuarios. Se rige por los principios del Software libre (distribución libre y abierta) y se enfoca en la estabilidad, seguridad y libertad del software, ofertando una amplia selección de paquetes. Mientras que CentOS pública versiones de forma conservadora Debian usa un modelo de lanzamiento "rolling release", actualizándose de forma continua. Los usuario pueden elegir entre ramas "stable", "testing" y "unstable"en función de sus necesidades de estabilidad/disponibilidad del Software. Usa el gestor de paquetes ```dpkg```, cuyo front-end es ```APT``` (Advanced Package Tool), con herramientas como ```apt-get``` o ```Aptitude``` (un apt de alto nivel)

## Diferencias entre apt y aptitude

Ambos son gestores de paquetes, pero Aptitude es una version más versatil de apt. APT es un administrador de paquetes de nivel inferior y aptitude es un administrador de paquetes de alto nivel. Otra gran diferencia es la funcionalidad que ofrecen ambas herramientas. Aptitude ofrece una mejor funcionalidad en comparación con apt-get. Ambos son capaces de de proporcionar los medios necesarios para realizar la gestión de paquetes. Sin embargo, si se busca un enfoque con mas caracteristicas, debería ser, Aptitude.

Otros gestores de paquetes usados en otras distribuciones de linux pueden ser:

| | |
|--|--|
|yum|OracleLinux / RedHat / Fedora |
|Pacman| ArchLinux |
| Entropy | Sabayon Linux |
| ZYpp | OpenSUSE/SUSE Linux Enterpruse |
|DNF / Dandified YUM | Fedora 22 |

* [Enlace explicando apt y apt-get en profundidad](https://terminaldelinux.com/terminal/administracion/instalar-paquetes-apt-get/)

## Qué es APPArmor

Es un módulo de seguridad basado en perfiles del kernel Linux.

Permite al administrador del sistema restringir los permisos de accesos de los programas y procesos de un sistema, de forma que se puedan prevenir y mitigar riesgos de seguridad.

Los perfiles especifican qué acciones pueden realizar las aplicaciones y a qué recursos pueden acceder, como archivos, directorios, sockets de red y otros recursos del sistema, de forma análoga a los permisos de los grupos de usuarios.

```sudo apparmor_status```

Otro perfil de seguridad similar es SELinux (Security-Enhanced Linux). Ambos sistemas tienen como objetivo mejorar la seguridad del sistema operativo, pero utilizan enfoques y modelos de implementación diferentes.

## Que es LVM

Es un gestor de volúmenes lógicos. Proporciona un método para asignar espacio en dispositivos de almacenamiento masivo, que es más flexible que los esquemas de particionado convencionales para almacenar volúmenes, permitiendo aumentar el tamaño del disco incluso cuando no hay espacio de disco contiguo libre. Ejemplo: Podrias tener una unidad virtual que coja 2gb de un disco, 30 de otro y 50 de otro.

# Simple Setup
# User

Para la creación de un nuevo usuario podemos usar ```sudo adduser [nombre_usuario]``` (más restrictivo) o ```sudo useradd  [nombre_usuario]``` (más user friendly). 

Para añadir una contraseña a ese usuario ```sudo passwd [nombre_usuario]```.

Para crearlo y añadirlo directamente a un grupo podemos hacer:

```sudo useradd [nombre_usuario] -m -g -G [nombre_grupo]```

| Opción | Explicación |
|--|--|
|**-m**| Para crearle un directorio de usuario en /home |
|**-g**| No crea un grupo que tenga el mismo nombre que el usuario |
|**-G**| Para añadirle a un grupo secundario |

Para ver si el usuario **jde-orma** está en los grupos *user42* y *sudo* hacemos:

```grep -E 'user42|sudo' /etc/group```

| Opción | Explicación |
|--|--|
|**-E**| Admite patrones regex de busqueda |

Para agregar un grupo a un usuario en cambio:

```sudo addgroup  [nombre_usuario] [nombre_grupo]```.

Para el chequeo de la **POLITICA DE CONTRASEÑA** segura se ha de comprobar:

| Opción | Explicación |
|--|--|
|```nano /etc/login.defs```| Donde se cambia el tiempo de expiración de la contraseña |
|```nano /etc/pam.d/common-password```| Donde añadimos las políticas de los caracteres de las contraseñas |
  

# Hostname & partitions
```lsblk```

# Check password rules
```
$ sudo cat /etc/login.defs
```
Cambiamos los siguientes valores en la sección *Password aging controls* del documento `login.defs`::
```
PASS_MAX_DAYS 30
PASS_MIN_DAYS 2
PASS_WARN_AGE 7
```
Además se ha de modificar el archivo de configuración `/etc/security/pwquality.conf`:
```
$ sudo cat /etc/security/pwquality.conf
```
Los valores a introducir son los siguientes:
```
# Number of characters in the new password that must not be present in the old password.
difok = 7
# The minimum acceptable size for the new password (plus one if credits are not disabled which is the default).
minlen = 10
# The maximum credit for having digits in the new password. If less than 0 it is the minimun number of digits in the new password.
dcredit = -1
# The maximum credit for having uppercase characters in the new password. If less than 0 it is the minimun number of uppercase characters in the new password.
ucredit = -1
# The maximum number of allowed consecutive same characters in the new password. The check is disabled if the value is 0.
maxrepeat = 3
# Whether to check it it contains the user name in some form. The check is disabled if the value is 0.
usercheck = 1
# Prompt user at most N times before returning with error. The default is 1.
retry = 3
# Enforces pwquality checks on the root user password. Enabled if the option is present.
enforce_for_root
```

# Sudo
Para ver la configuración del sudo:

```sudo visudo```

	Defaults	passwd_tries=3
	Defaults	badpass_message="Wrong Password. Keep calm and keep trying!"
	Defaults	logfile="/var/log/sudo/sudo.log"
	Defaults	log_input,log_output
	Defaults	iolog_dir="/var/log/sudo"
	Defaults	requiretty/	
	Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"

o

```sudo nano /etc/sudoers```

El *requiretty* puede ser un poco confuso si no se estudia bien. El requerimiento de TTY (Teletypewriter) sirve para comprobar si un comando de sudo se está ejecutando desde una terminal por alguien frente a si se ejecuta automáticamente dentro de un script desde un servicio (con Crontab, ejecutándolo desde otro script...)

Otra nota importante es que mientras que la terminal de una MV devuelve ```/dev/ttyN``` cuando se ejecuta este comando desde un terminal ssh devuelve ```/dev/pts/N```(donde N es el número asociado a la terminal) por ser un pseudo-tty (una pseudo terminal).

Ejecutando ```who``` la terminal muestra el listado de terminales conectadas a la MV. En este ejemplo se ve que hay 2 terminales de ssh y 1 en la propia máquina:

> jde-orma tty1         2023-07-09 10:07

> jde-orma pts/1        2023-07-10 12:47 (192.168.56.1)

> jde-orma pts/2        2023-07-10 12:48 (192.168.56.1)


Para chequear que el log de sudo está guardando los comandos correctamente se puede abrir un cliente ssh que ejecute un tail en el archivo objetivo (-f para que se actualice):

```tail -f /var/log/sudo/sudo.log```

| Opción | Explicación |
|--|--|
|```-f```| Para que actualice el EOF |

Como alternativa se puede hacer
```getent group user42``` y ```getent group sudo```.

# UFW
Para ver los puertos habilitados de ufw: 

``` sudo ufw status ``` o ```sudo nano /etc/ufw/user.rules```

Para ver el estado del servicio/daemon ufw:

```systemctl status ufw``` o ```sudo service ufw status```

Para habilitar o deshabilitar puertos:

```sudo ufw allow/deny 8080```

# SSH
Para ver el puerto configurado para ssh

```grep -E 'Port |PermitR' /etc/ssh/sshd_config```

# Script Monitoring

## Crontab

Para acceder al archivo de configuración de Cron usamos:

```sudo crontab -u root -e```

| Opción | Explicación |
|--|--|
|```-u```| Usuario que va a editar el archivo |
|```-e```| Abre el archivo de configuración de Cron con el editor por defecto definido en las variables del sistema |


o en su defecto se puede ver abrir directamente el archivo en ```/var/spool/cron/crontabs```, pero no se recomienda, ya que solo se puede abrir como root.

## Script
Guardamos el script en el usuario ***home/root***.

```
#!/bin/bash
# OS architecture and kernel version:
# uname da la información del Kernel y de la arquitectura del SO:
# -s indica que kernel usa [Linux]
# -r indica la vesion [5.10.0], los paquetes añadidos a esta [-21] y su arquitectura [-amd64]
# -v indica la distribución del SO [#1 SMP Debian 5.10.0.162-1 (2023-01-21)
# -m indica el procesador de la maquina [x86_64]
# -o indica el SO [GNU/Linux]
ARCH=$(uname -srvmo)
# Numero de procesadores fisicos (si pone 0 es que hay 1, por eso el wc)
PCPU=$(grep 'physical id' /proc/cpuinfo | uniq | wc -l)
# Numero de procesadores virtuales (si pone 0  es que  hay 1, por eso el wc)
VCPU=$(grep processor /proc/cpuinfo | uniq | wc -l)
# RAM disponible del servidor y su porcentaje de uso:
RAM_TOTAL=$(free -h --mega | grep Mem | awk '{print $2}')
RAM_USED=$(free -h --mega | grep Mem | awk '{print $3}')
RAM_PERC=$(free -k | grep Mem | awk '{printf("%.2f%%"), $3 / $2 * 100}')
# Espacio de almacenamiento del servidor y su porcentaje de uso:
DISK_TOTAL=$(df -h --total | grep total | awk '{print $2}')
DISK_USED=$(df -h --total | grep total | awk '{print $3}')
DISK_PERC=$(df -k --total | grep total | awk '{print $5}')
# Porcentaje de uso del procesados. El b hace una instantanea de 1 iteracion:
CPU_LOAD=$(top -bn1 | grep '^%Cpu' | xargs | awk '{printf("%.1f%%"), $2 + $4}')
# Ultimo arranque del sistema:
LAST_BOOT=$(who -b | awk '{print($3 " " $4)}')
# alt: $(who -b | awk G')
# Saber si hay configurados Volumenes Logicos:
LVM=$(if [ $(lsblk | grep lvm | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
# Numero de conexiones activas:
# TCP=$(grep TCP /proc/net/sockstat | awk '{print $3}')
TCP=$(ss -ta | grep ESTAB | wc -l)
# Numero de usuarios usando el servidor:
USER_LOG=$(who | wc -l)
# Direccion IP y MAC:
IP_ADDR=$(hostname -I | awk '{print $1}')
MAC_ADDR=$(ip link show | grep link/ether | awk '{print $2}')
# Numero de comandos usados con SUDO:
SUDO_LOG=$(cat /var/log/sudo/sudo.log | grep -a 'USER' | wc -l)
# Imprimir en todos los terminales:
echo " # Architecture : "$ARCH
echo " # CPU physical : "$PCPU
echo " # vCPU : "$VCPU
echo " # Memory Usage : "$RAM_USED"/"$RAM_TOTAL" ("$RAM_PERC")"
echo " # Disk Usage : "$DISK_USED"/"$DISK_TOTAL" ("$DISK_PERC")"
echo " # CPU load : "$CPU_LOAD
echo " # Last boot : "$LAST_BOOT
echo " # LVM use : "$LVM
echo " # Connections TCP : "$TCP" established"
echo " # User log : "$USER_LOG
echo " # Network : IP "$IP_ADDR" (MAC "$MAC_ADDR")"
echo " # Sudo : "$SUDO_LOG" cmd"
```
Usamos ```uname -srvmo``` para conseguir solo la información que queremos, ya que ```-a``` nos devuelve tambien el nombre de la máquina.

Usamos ```free``` para la memoria RAM usada y mostrar los datos recogiendo la línea Mem con ```grep``` y los valores deseados con ```awk```. Mientras que ```-h``` nos da los valores en bytes ```-k``` nos los valores en bits.

Usamos ```df``` para ver el espacio en disco.

Usamos ```top -bn1``` para mostrar los procesos de linux y su porcentaje de uso. Si no se indica el ```-b``` (batch) ```-n``` (number) ```-1``` (1 iteración) el sistema nos mostrará sus datos en tiempo real, por lo que así solo muestra una iteración o instantanea del sistema.

Usamos ```who``` que muestra quien está logueado con ```-b``` para que muestre el timestamp del último boot.

Con ```lsblk``` mostramos la información de las particiones físicas y los volumenes lógicos. En caso de que al hacer *grep lvm* no se devuelvan líneas nuevas (*wc -l*) diremos que NO hay LVMs configurados, pero en caso contrario diremos que sí

# Comandos utiles

Parece que cada servicio que se instala en GNU/Linux crea una carpeta en **/etc** para almacenar sus archivos de configuración.

Si usas la opción de ```grep -E``` puedes hacer una especie de AND poniendo el valor de busqueda entre comillas simples, de forma que puedes buscar los archivos de todos los servicios que te interesen así:


```ls -l /etc | grep -E 'cron|ssh|ufw|php' ```

# Creación de la firma de la MV

```sha1sum jde-orma42.vdi```

# BIBLIOGRAFIA
* [INFO SOBRE DIRECTORIOS DE LINUX](https://computernewage.com/2015/06/14/el-arbol-de-directorios-de-linux-al-detalle-que-contiene-cada-carpeta/#estructura-directorios)
* [INFO SOBRE COMO SE MANTIENE EL KERNEL DE LINUX](https://superuser.com/questions/1003057/what-is-the-exact-different-between-linux-kernel-release-and-version#:~:text=In%20Linux%20based%20operating%20system,different%20between%20Release%20and%20Version%20%3F&text=%22Release%22%2C%20it%20probably%20means,from%20source%2C%20may%20be%20unstable.) (```uname -a```)
  
* [INFO SOBRE GESTORES PAQUETES DE LINUX](https://www.profesionalreview.com/2016/09/11/gestor-de-paquetes-en-linux/#:~:text=Entropy%20es%20comparable%20a%20Apt,Entropy%20tambi%C3%A9n%20incluye%20accesos%20directos.)
