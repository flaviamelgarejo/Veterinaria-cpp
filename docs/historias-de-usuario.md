# Historias de usuario

Formato: **Como** [rol], **quiero** [acción], **para** [objetivo].

Los diagramas de archivos, de clases y de flujo están en el [PDF](historias-de-usuario.pdf).

## Módulo 1: Clientes

*No depende de otros módulos.*

- **HU 01 (Alta):** Como recepcionista, quiero registrar un nuevo cliente para guardar sus datos de contacto en el sistema.
- **HU 02 (Consulta):** Como recepcionista, quiero listar todos los clientes activos para buscar rápidamente su número de ID. *Depende de HU 01.*
- **HU 03 (Modificación):** Como recepcionista, quiero modificar los datos de un cliente para actualizar su teléfono o dirección si se muda. *Depende de HU 01.*
- **HU 04 (Baja lógica):** Como administrador, quiero dar de baja a un cliente (ocultarlo) si ya no asiste a la clínica, sin borrar su historial. *Depende de HU 01.*

## Módulo 2: Mascotas

*Depende de Clientes: cada mascota necesita un dueño.*

- **HU 05 (Alta):** Como recepcionista, quiero registrar una nueva mascota asociándola al ID de su dueño, para abrir su historia clínica. *Depende de HU 01.*
- **HU 06 (Consulta):** Como recepcionista, quiero buscar un ID de cliente y ver la lista de sus mascotas registradas, para saber qué animal trajo a la consulta. *Depende de HU 05.*
- **HU 07 (Modificación):** Como recepcionista, quiero modificar los datos de una mascota para actualizar su edad o peso. *Depende de HU 05.*
- **HU 08 (Baja lógica):** Como recepcionista, quiero dar de baja el registro de una mascota en caso de fallecimiento, manteniendo intactas sus atenciones pasadas. *Depende de HU 05.*

## Módulo 3: Veterinarios

*No depende de otros módulos.*

- **HU 09 (Alta):** Como administrador, quiero registrar a un nuevo veterinario para agregarlo al plantel de la clínica.
- **HU 10 (Consulta):** Como recepcionista, quiero listar a los veterinarios activos para saber a quién asignarle un turno. *Depende de HU 09.*
- **HU 11 (Baja lógica):** Como administrador, quiero dar de baja a un veterinario si deja de trabajar en la clínica. *Depende de HU 09.*

## Módulo 4: Catálogo de procedimientos

*No depende de otros módulos.*

- **HU 12 (Alta):** Como administrador, quiero registrar un nuevo procedimiento médico o estético con su precio, para tener un catálogo de servicios.
- **HU 13 (Modificación):** Como administrador, quiero modificar el precio de un procedimiento para mantener los valores actualizados. *Depende de HU 12.*
- **HU 14 (Consulta):** Como recepcionista, quiero ver el listado de procedimientos y precios para informar a los clientes. *Depende de HU 12.*
- **HU 15 (Baja lógica):** Como administrador, quiero quitar un procedimiento que ya no ofrecemos, para que desaparezca de las opciones pero se mantenga para los reportes de meses anteriores. *Depende de HU 12.*

## Módulo 5: Atenciones

*Depende de todos los módulos anteriores.*

- **HU 16 (Alta):** Como recepcionista, quiero registrar una nueva atención vinculando la mascota, el veterinario y el procedimiento, para dejar registro de la visita. *Depende de HU 05, HU 09 y HU 12.*
- **HU 17 (Baja lógica):** Como recepcionista, quiero anular una atención cargada por error. *Depende de HU 16.*
- **HU 18 (Historial):** Como veterinario, quiero ingresar el ID de una mascota y ver todas sus atenciones pasadas en orden, para conocer su historia clínica. *Depende de HU 16.*

## Módulo 6: Reportes y estadísticas

*Depende de que todos los módulos anteriores funcionen.*

- **HU 19 (Recaudación mensual):** Como dueño, quiero ingresar un mes y año para ver lo recaudado en todos los procedimientos.
- **HU 20 (Recaudación por profesional):** Como administrador, quiero un reporte por rango de fechas para saber qué veterinario generó más ingresos.
- **HU 21 (Demanda por día):** Como dueño, quiero saber qué días de la semana tienen más y menos atenciones, para organizar turnos y francos del personal.
- **HU 22 (Estadística por especie):** Como dueño, quiero ver las atenciones agrupadas por especie, para gestionar el stock de insumos.
- **HU 23 (Top procedimientos):** Como administrador, quiero ver los 3 procedimientos más pedidos del año, para armar promociones.
- **HU 24 (Clientes VIP):** Como recepcionista, quiero un listado de los clientes con más visitas en el año, para enviarles un regalo.
- **HU 25 (Mascotas inactivas):** Como dueño, quiero ver las mascotas que no tuvieron atenciones en el último año, para recordarles a los dueños el chequeo anual.
