# Jenkins Pipeline C

## Setup 

There a many ways to setup a Jenkins server - it depends on our use case.

### WAR File Setup 

A **WAR (Web Application Archive)** is a Java web application packaged for 
deployment. The Jenkins WAR can be run directly with a compatible Java 
runtime (for example, JDK 21) using `java -jar jenkins.war`, so we can 
start Jenkins without installing a separate application server.

* Download Jenkins Generic Java package (.war): [https://www.jenkins.io/download/](https://www.jenkins.io/download/) 

* In the download directory
    ```bash
    $ java -jar jenkins.war --httpPort=8080
    ```

* Browse to http://localhost:8080

* Follow the instructions to complete the installation

## Jenkins Job Configuration

We need the following settings for a new Jenkins job:

* New Item 
	- Pipeline
    - Description (optional)
    - Build Triggers 
	    - Poll SCM: `H/1 * * * *`
    - Pipeline / Definition: 
      - Pipeleine: Pipeline Script from SCM: 
        - SCM: Git 
        - Repository URL: `https://github.com/teiniker/jenkins-pipeline-c.git` 
        - Branches to build: `*/main` 
      - Script Path: Jenkinsfile

Save these settings.

## Commit Pipeline

The most **basic Continuous Integration process** is called a commit pipeline.

This phase starts with a commit (or push in Git) to the main repository and results in a report about 
the build success or failure. 

Since it runs after each change in the code, **the build should take no more than five minutes** and 
should consume a reasonable amount of resources.

The commit phase works as follows: a developer checks in the code to the repository, the Continuous Integration server detects the change, and the build starts. 
The most fundamental commit pipeline contains three stages: 
* **Checkout**: This stage downloads the source code from the repository. 

* **Compile**: This stage compiles the source code. 

* **Unit test**: This stage runs a suite of unit tests.


## References

* [YouTube: How to Install Jenkins](https://youtu.be/CEyfsQq3QEM)
* [YouTube: Complete Jenkins Pipeline Tutorial](https://youtu.be/7KCS70sCoK0)
* [Getting started with Pipeline](https://www.jenkins.io/doc/book/pipeline/getting-started/)
* [Using a Jenkinsfile](https://www.jenkins.io/doc/book/pipeline/jenkinsfile/)

* Rafał Leszko. **Continuous Delivery with Docker and Jenkins: Create secure applications by building complete CI/CD pipelines**. Packt Publishing, 2nd Edition 2019.


*Egon Teiniker, 2024-2025, GPL v3.0* 
		
