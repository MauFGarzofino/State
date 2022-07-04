# State Pattern

- En una situación en la que un objeto cambia su comportamiento de acuerdo con un estado específico, el objeto mismo verifica el estado
y no llama a una acción de acuerdo con el estado, pero **objetiva el estado** y lo delega para que una acción pueda ser realizado de acuerdo con el estado.

## Términos relacionados
### state
- Esta es la **interfaz** que representa el estado.
- Una clase de estado que ejemplifica esta interfaz y se puede usar en lugar de la clase de estado existente.

### ConcreteState
- Ejecuta la operación solicitada por el objeto `Context` en la forma implementada según su estado.
- En general, también determina el siguiente estado y solicita un cambio de estado al objeto 'Contexto'.
- Condición o situación que puede tener un objeto mientras existe en un sistema.

### Context
- Realiza el rol de usar **estado**.
- Hay variables de estado que representan el estado y varias variables que constituyen el estado del sistema actual.
- Se proporciona una función para cada clase de estado para solicitar un cambio de estado y cambiar el estado.
- La función `request` **delega** la ejecución de la acción al objeto de estado correspondiente en lugar de ejecutar la acción real.

## Característica
- Permite que el objeto cambie su comportamiento de acuerdo al estado interno del objeto.
- Dado que las acciones que se ajustan al estado se separan en clases de estado, cada estado se puede gestionar de forma estructurada.
- El patrón de estado se usa principalmente para reemplazar declaraciones condicionales.
- El patrón de estado también aumenta en complejidad a medida que aumenta el número de clases relacionadas.
- El código es conciso y se mejora la legibilidad.
- Puedes **transformar estados por ti mismo** instruyendo una transformación de estado al final de la lógica de cada estado.

## ejemplo
- [State](/State/state.cpp)

## Explicacion
- Simulamos un Humano que tendrá solo 3 estados, caminar, correr y morir.
