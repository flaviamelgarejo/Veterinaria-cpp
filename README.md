# Gestión de Clínica Veterinaria 🐾

Trabajo práctico integrador de **Programación II** (Tecnicatura Universitaria en Programación, UTN, 2026). Hecho en grupo.

Es un sistema por consola, en C++ con Code::Blocks, para organizar el día a día de una veterinaria: clientes, mascotas, veterinarios, servicios y atenciones.

## Qué hace
- Alta, listado, búsqueda, modificación y baja de clientes, mascotas, veterinarios, procedimientos y atenciones.
- Las bajas no borran nada: el registro queda oculto para no perder el historial.
- Al cargar una atención, controla que la mascota, el veterinario y el procedimiento existan y estén activos.
- Guarda lo que se cobró en cada atención, aunque después cambie el precio.
- Busca las mascotas de un cliente por su DNI y las atenciones entre dos fechas.
- Muestra todas las atenciones que hizo un veterinario.
- Lista los clientes VIP (los que tienen más de una mascota).
- Informes: recaudación por mes, por veterinario y por procedimiento, y los 3 procedimientos más pedidos.

## Cómo lo organizamos
Antes de programar escribimos las **historias de usuario** (qué necesita cada persona de la clínica), los diagramas de archivos y de clases, y un diagrama de cómo se usa el sistema. Cada uno trabajó en su rama y juntamos todo con pull requests en GitHub.

- [Historias de usuario](docs/historias-de-usuario.md)
- [Diagramas de archivos, clases y flujo](docs/historias-de-usuario.pdf)
- [Informe que presentamos con el proyecto](docs/informe-del-proyecto.pdf)

## Qué practicamos
Clases, herencia (`Cliente` y `Veterinario` heredan de `Persona`), archivos binarios `.dat` para guardar los datos, y separar el código en archivos `.h` y `.cpp`.

## Cómo probarlo
Abrir `Veterinaria_Proyecto.cbp` con Code::Blocks. Funciona en Windows. Los archivos `.dat` se crean solos al cargar el primer dato.

## Equipo
Juan Ciuffo, Damián Ramos y Flavia Melgarejo.
