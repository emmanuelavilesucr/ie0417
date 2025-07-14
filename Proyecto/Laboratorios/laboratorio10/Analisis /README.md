# SonarQube
## Analisis general:

![CodigoGeneral](https://github.com/DAcosta3103/ie0417-proyecto/blob/main/Laboratorios/laboratorio10/Analisis%20/Imagenes/CodigoGeneral.png)

![Actividad](https://github.com/DAcosta3103/ie0417-proyecto/blob/main/Laboratorios/laboratorio10/Analisis%20/Imagenes/Actividad.png)

En general los resultados arrojados por SonarQube muestran un panorama muy positivos. Por otro lado, el análisis sugiere que el sitio web necesita mejorar su seguridad y fiabilidad. Además, se sugiere implementar testing automático para elevar la cobertura, y reducir las duplicaciones mediante refactorización para que el proyecto sea más sostenible.


- **Seguridad:**  La calificación es la mas baja del índice de calidad. El código posee **377 puntos de acceso de seguridad** y **9 cuestiones abiertas**, lo cual debería de revisarse para evitar fugas de información

- **Fiabilidad:** Posee **2.6k cuestiones abiertas**. La calificación de Fiabilidad también es baja, estos errores potenciales podrían provocar fallos en tiempo de ejecución. Una califica D sugiere que la base de código es propensa a bugs.

- **Mantenibilidad:** La calificación es A, lo que es positivo, lo que significa que a pesar de  tener **7k cuestiones abiertas**, la proporción o el impacto de esos problemas es bajo. Esto sugiere que los problemas son mayormente de estilo y no críticos para el mantenimiento.

- **Cobertura:** La cobertura es de **0.0%**, lo que podría deberse a que no se han realizado tests automáticos en el código, esto puede impedir que se detecten errores automáticamente antes de desplegar cambios.

- **Duplicación:** El porcentaje de Duplicación es **29.3%** sobre **279k líneas**. Es significa que alrededor de una tercera parte del código se repite. Lo que puede provocar errores.

- **Problemas aceptados:** No existen problemas aceptados, lo que significa que no hay debilidades encontradas o también, podría deberse a que nadie ha realizado un análisis a profundidad sobre la jerarquía de problemas a resolver.

![Severidad](https://github.com/DAcosta3103/ie0417-proyecto/blob/main/Laboratorios/laboratorio10/Analisis%20/Imagenes/Severidad.png)

- La **Severidad** clasifica los problemas según su impacto potencial en la calidad del código. Los **Blocker** son problemas críticos, que pueden provocar que el sistema falle por completo o que sea inseguro o inutilizable. Los problemas **High**, son errores severos que pueden provocar fallos en entornos productivos. Los **Medium** representan problemas que impactan la calidad y el mantenimiento, pero que no detendrán el sistema.**Low** y **Info** son **Issues menores**, y se refieren mas convenciones del código y sugerencias informativas que ayudan a mejorar la legibilidad y consistencia del código.


- De acuerdo con el análisis realizado por **SonarQube**, el código posee varias categorías de problemas. Los 67 problemas de categoría **Blocker** son la mayor urgencia, dado a que representan los riesgos más serios para la estabilidad, seguridad o funcionamiento del sistema. Posteriormente, se podrían abordar los **4.6k** problemas **High**, ya que tienen gran impacto en calidad y experiencia del usuario, y por ultimo los **Low** y **Info**.

## Graficos:

### Fiabilidad:

![Fiabilidad](https://github.com/DAcosta3103/ie0417-proyecto/blob/main/Laboratorios/laboratorio10/Analisis%20/Imagenes/Fiabilidad.png)

### Cobertura:

![Cobertura](https://github.com/DAcosta3103/ie0417-proyecto/blob/main/Laboratorios/laboratorio10/Analisis%20/Imagenes/Cobertura.png)

### Mantenibilidad:

![Mantenibilidad](https://github.com/DAcosta3103/ie0417-proyecto/blob/main/Laboratorios/laboratorio10/Analisis%20/Imagenes/Mantenibilidad.png)

### Duplicacion:

![Duplicacion](https://github.com/DAcosta3103/ie0417-proyecto/blob/main/Laboratorios/laboratorio10/Analisis%20/Imagenes/Duplicaciones.png)


### Riesgo:

![Riesgo](https://github.com/DAcosta3103/ie0417-proyecto/blob/main/Laboratorios/laboratorio10/Analisis%20/Imagenes/Riesgo.png)



