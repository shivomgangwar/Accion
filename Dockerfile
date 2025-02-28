# Use a secure and minimal base image
FROM nginx:1.19-alpine

LABEL maintainer = " Shiv Gangwar" \
      description = "Secure NGINX  1.19 Container" \
      version = "1.19"

# Set a non-root user for better security
RUN addgroup -S nginx && adduser -S nginx -G nginx

# Ensure the user has appropriate permissions
RUN chown -R nginx:nginx /var/cache/nginx /var/run /var/log/nginx

# Switch to the non-root user
USER nginx

# Expose port 80 (default for Nginx)
EXPOSE 80

# Start Nginx in foreground (required for containerized apps)
CMD ["nginx", "-g", "daemon off;"]
