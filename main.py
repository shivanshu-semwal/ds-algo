import os

def define_env(env):
    @env.macro
    def include_file(filename, start_line=0, end_line=None):
        full_filename = os.path.join(
            env.project_dir,
            'docs',
            '/'.join(env.page.file.src_uri.split('/')[:-1]),
            filename
        )
        with open(full_filename, 'r') as f:
            lines = f.readlines()
        line_range = lines[start_line:end_line]
        # print('/'.join(env.page.file.src_uri.split('/')[:-1]))
        return ''.join(line_range)

    @env.macro
    def doc_env():
        "Document the environment"
        return {name:getattr(env, name) for name in dir(env) if not name.startswith('_')}