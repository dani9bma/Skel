
#pragma once

#include "Components/Model.h"
#include "../Graphics/shader.h"
#include "Components/Component.h"
#include "Components/MeshComponent.h"
#include "Components/Transform.h"

#include <EASTL/unordered_map.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Skel
{
    
	class SKEL_API Entity
	{
        private:
		eastl::unordered_map<ComponentType*, Component*> m_components;
		Transform m_transform;
		Shader* m_shader;
		bool m_visible = true;
        public:
		Entity() { }
		Entity(Model* mesh, Shader* shader);
		void addComponent(Component* component);
		void draw();
		void setSize(float x, float y, float z);
		void setRotation(float angle, bool x = true, bool y = true, bool z = true);
		void setPosition(float x, float y, float z);
		void setTransform(glm::vec3 position, glm::vec3 size, glm::vec3 rotation, float angle);
		void setVisibility(bool visible);
		void SetTransformMatrix(glm::mat4 matrix);
        
		template <typename T>
            T* getComponent()
		{
			ComponentType* type = T::getStaticType();
			auto it = m_components.find(type);
			if (it == m_components.end())
				return nullptr;
            
			return (T*)it->second;
		}
        
		inline Transform getTransform() const { return m_transform; }
	};
}