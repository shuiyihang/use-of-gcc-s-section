
#include "device.h"
#include "stdio.h"

#include "string.h"

struct device *device_get_binding(const char *name)
{
	struct device *info;

	for (info = __device_init_start; info != __device_init_end; info++) {
		if (info->driver_api && !strcmp(name, info->config->name)) {
			return info;
		}
	}

	return NULL;
}