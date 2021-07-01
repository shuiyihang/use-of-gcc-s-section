
#ifndef __DEVICE_H__
#define __DEVICE_H__

struct device;

struct device_config {
	char	*name;
	int (*init)(struct device *device);
};

struct device {
    const struct device_config *config;
	const void *driver_api;
};


#define DEVICE_AND_API_INIT(dev_name, init_fn, api) \
	static const struct device_config __config_##dev_name \
	__attribute__((__section__(".dev.init"))) = { \
		.name = #dev_name, \
        .init = (init_fn), \
	}; \
	static const struct device __device_##dev_name \
	__attribute__((__section__(".init_api"))) = { \
        .config = &__config_##dev_name,\
		.driver_api = api, \
	}

extern struct device __device_init_start[];
extern struct device __device_init_end[];

struct device *device_get_binding(const char *name);

#endif