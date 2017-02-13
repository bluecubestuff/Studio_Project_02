
#ifndef UTILITY_H
#define UTILITY_H

#include "GL\glew.h"
#include "shader.hpp"
#include "Mtx44.h"
#include "Application.h"
#include "MeshBuilder.h"
#include "DetectMemoryLeak.h"

Position operator*(const Mtx44& lhs, const Position& rhs);

#endif