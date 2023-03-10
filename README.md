![shool_year](https://img.shields.io/badge/shool_year-second-blue)
![duration](https://img.shields.io/badge/duration-3_weeks-blue)  

<img src="https://user-images.githubusercontent.com/91843760/221444139-cb844cc6-f889-40ed-8dd6-5833b888df87.png" width=25% height=25%><img src="https://user-images.githubusercontent.com/91843760/221444137-040e392a-935f-460f-b365-b69d7a9956ef.png" width=25% height=25%><img src="https://user-images.githubusercontent.com/91843760/221444138-2e3fc6ce-1582-43ce-959f-585d0ce94962.png" width=25% height=25%>

## **Informations**

This project allowed us to discover and implement several graphic effects with modern OpenGL.

## **Remarks**

Concerning demo_shader (13/13), you must modify the light position or disable/enable it to apply the correct colors.  
Same goes for demo_npr_toon (10/13).

You can use the fantasy game inn with the demo_npr_toon/gooch, for this you have to :
- uncomment the second MeshBuffer in npr_gooch/toon_scene.cpp (line 23)
- uncomment color1 in the fragment shader in demo_npr_toon.cpp (line 90)
- uncomment texture parts in diffuseColor and emissiveColor in demo_npr_toon/gooch.cpp
in the fragShader
``` c++       
vec3 diffuseColor  = gDefaultMaterial.diffuse * lightResult.diffuse; // * texture(uDiffuseTexture, vUV).rgb;
```
```c++
vec3 emissiveColor = gDefaultMaterial.emission; // + texture(uEmissiveTexture, vUV).rgb;
```

## **Implemented effects**

Feature                            | Files (.cpp / .h)
-------                            | ------
Skybox, reflection, refraction     | demo_skybox <br> demo_reflection
NPR                                | demo_npr_gooch<br>demo_npr_toon <br>                                  npr_gooch_scene<br>npr_toon_scene
Gamma correction                   | demo_gamma
Instancing                         | demo_instancing
Classic shading modes              | demo_shading <br> shader_scene
