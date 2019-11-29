# SECURITY WARNING: don't run with debug turned on in production!
# WARNING: Setting to False resultet inn 404 for all /static urls :(
# With debug turned off Django won't handle static files for you any more - your production web server (Apache or something) should take care of that.
DEBUG = True

ALLOWED_HOSTS = ['localhost', 'website']
STATIC_ROOT = '/static/'

# SECURITY WARNING: keep the secret key used in production secret!
SECRET_KEY = '24kgEwufw999WMzQaDzWhWSwH69PYCJPgWPh4cX8'

DATABASES = {
    'default': {
        'ENGINE': 'django.db.backends.mysql',
        'NAME': 'snake',
        'USER': 'root',
        'PASSWORD': 'Uu5ZyuXcQHLcMBQeC9Uih4AWjJuswM3SNCmNS8E8',
        'HOST': '127.0.0.1',
        'PORT': '3306',
    }
}
